#include "unity.h"
#include "Evaluate.h"
#include "Token.h"
#include "LinkedList.h"
#include "mock_Stack.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "mock_Text.h"
#include "mock_createNumberToken.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/***********************************************************************	
 Test on function operatorEvaluate
 Input parameter : 
					1)Stack *numberStack
					2)Operator *opeToken

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								
 ***********************************************************************/	
 
 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){
	
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	ErrorCode exception;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"1#2"};
	Number number1 = {.type= NUMBER_TOKEN, .value=1};
	Operator hashTag = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(HASH_OP)};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	
	stackPop_ExpectAndReturn(&numberStack,&number1);
	stackPop_ExpectAndReturn(&numberStack,&number2);
	
	Try{
		 operatorInfixEvaluate(&numberStack,&hashTag);
		TEST_FAIL_MESSAGE("Invalid Operator should throw Error Not Operator");
	}
	Catch(exception){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERATOR,exception);
	}
}	

void test_operatorEvaluate_3_PLUS_7(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"3+7"};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number7 = {.type= NUMBER_TOKEN, .value=7};
	Number number10;
	
	stackPop_ExpectAndReturn(&numberStack,&number7);
	stackPop_ExpectAndReturn(&numberStack,&number3);
	createNumberToken_ExpectAndReturn(10,(Token*)&number10);
	stackPush_Expect(&number10,&numberStack);
	
	operatorInfixEvaluate(&numberStack,&plus);
}


void test_operatorEvaluate_100_MINUS_37(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"100-37"};
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number37 = {.type= NUMBER_TOKEN, .value=37};
	Number number63;
	
	
	stackPop_ExpectAndReturn(&numberStack,&number37);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(63,(Token*)&number63);
	stackPush_Expect(&number63,&numberStack);
	
	operatorInfixEvaluate(&numberStack,&minus);
}

void test_operatorEvaluate_100_MULTIPLY_50(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"100*50"};
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator multiply = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(MUL_OP)}; 
	Number number50 = {.type= NUMBER_TOKEN, .value=50};
	Number number5000;
	
	stackPop_ExpectAndReturn(&numberStack,&number50);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(5000,(Token*)&number5000);
	stackPush_Expect(&number5000,&numberStack);
	
	operatorInfixEvaluate(&numberStack,&multiply);
}

void test_operatorEvaluate_99_DIVIDE_3(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"99/3"};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator divide = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)}; 
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number33;
	
	stackPop_ExpectAndReturn(&numberStack,&number3);
	stackPop_ExpectAndReturn(&numberStack,&number99);
	createNumberToken_ExpectAndReturn(33,(Token*)&number33);
	stackPush_Expect(&number33,&numberStack);
	
	operatorEvaluate(&numberStack,&divide);
}
/*
void test_operatorEvaluate_60_MODULUS_7(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60%7", .startIndex = 0, .length=3};
	Number number60 = {.type= NUMBER, .value=60};
	Operator modulus = {.type= OPERATOR, .id=MODULUS , .precedence=100};
	Number number7 = {.type= NUMBER, .value=7};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number7);
	stackPop_ExpectAndReturn(&numberStack,&number60);
	createNumberToken_ExpectAndReturn(4,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&modulus);
}

void test_operatorEvaluate_45_BITWISEAND_54(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "45&54", .startIndex = 0, .length=3};
	Number number45 = {.type= NUMBER, .value=45};
	Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND , .precedence=20};
	Number number54 = {.type= NUMBER, .value=54};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number54);
	stackPop_ExpectAndReturn(&numberStack,&number45);
	createNumberToken_ExpectAndReturn(36,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseAND);
}

void test_operatorEvaluate_56_BITWISEOR_30(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "56|30", .startIndex = 0, .length=3};
	Number number56 = {.type= NUMBER, .value=56};
	Operator bitwiseOR = {.type= OPERATOR, .id=BITWISE_OR , .precedence=10};
	Number number30 = {.type= NUMBER, .value=30};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number30);
	stackPop_ExpectAndReturn(&numberStack,&number56);
	createNumberToken_ExpectAndReturn(62,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseOR);
}

void test_operatorEvaluate_56_BITWISEXOR_30(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "56^30", .startIndex = 0, .length=3};
	Number number56 = {.type= NUMBER, .value=56};
	Operator bitwiseXOR = {.type= OPERATOR, .id=BITWISE_XOR , .precedence=10};
	Number number30 = {.type= NUMBER, .value=30};
	Number answer;
	Token *answerToken=(Token*)&answer;
	
	stackPop_ExpectAndReturn(&numberStack,&number30);
	stackPop_ExpectAndReturn(&numberStack,&number56);
	createNumberToken_ExpectAndReturn(38,answerToken);
	stackPush_Expect(&answer,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseXOR);
}
*/
/***********************************************************************	
 Test on function evaluateAllOperatorOnStack
 Input parameter : 
					1)Stack *numberStack
					2)Stack *operatorStack
					
 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)operatorEvaluate
								
 ***********************************************************************/	
 /*
 void test_evaluateAllOperatorOnStack_2_plus_3_plus_4(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3+4", .startIndex = 0 ,.length=5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator add = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token4 = (Token*)&add;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=5};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//2+3
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(5,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//5+4
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(9,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_10_plus_3_multiply_9(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "10+3*9", .startIndex = 0, .length=5};
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token1 = (Token*)&number10;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number9 = {.type= NUMBER, .value=9};
	Token *token5 = (Token*)&number9;
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=13};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//10+3
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(13,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//13*9
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(117,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_100_divide_5_plus_60(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100/5+60", .startIndex = 0, .length=5};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator divide = {.type= OPERATOR, .id=DIVIDE ,.precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token3 = (Token*)&number5;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number60 = {.type= NUMBER, .value=60};
	Token *token5 = (Token*)&number60;
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=20};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(20,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//20+60
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(80,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}	

void test_evaluateAllOperatorOnStack_99_XOR_66_divide_11_plus_10(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "99^66/11+10", .startIndex = 0, .length=7};
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token1 = (Token*)&number99;
	
	Operator bitwiseXOR = {.type= OPERATOR, .id=BITWISE_XOR ,.precedence=50};
	Token *token2 = (Token*)&bitwiseXOR;
	
	Number number66 = {.type= NUMBER, .value=66};
	Token *token3 = (Token*)&number66;
	
	Operator divide = {.type= OPERATOR, .id=DIVIDE ,.precedence=100};
	Token *token4 = (Token*)&divide;
	
	Number number11 = {.type= NUMBER, .value=11};
	Token *token5 = (Token*)&number11;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token6 = (Token*)&plus;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token7 = (Token*)&number10;
	
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=33};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number tempAnswer2 = {.type= NUMBER, .value=3};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;

	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//99^66
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(33,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//33/11
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(3,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	
	//3+10
	stackPop_ExpectAndReturn(&operatorStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(13,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100/5*6+99-20", .startIndex = 0, .length=9};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token3 = (Token*)&number5;
	
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token5 = (Token*)&number6;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token6 = (Token*)&plus;
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token7 = (Token*)&number99;
	
	Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};
	Token *token8 = (Token*)&minus;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token9 = (Token*)&number20;

	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=20};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number tempAnswer2 = {.type= NUMBER, .value=120};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type= NUMBER, .value=219};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(20,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(120,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(219,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(199,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20_modulus_30(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100/5*6+99-20%30", .startIndex = 0, .length=11};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token3 = (Token*)&number5;
	
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token5 = (Token*)&number6;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token6 = (Token*)&plus;
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token7 = (Token*)&number99;
	
	Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};
	Token *token8 = (Token*)&minus;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token9 = (Token*)&number20;
	
	Operator modulus = {.type= OPERATOR, .id=MODULUS ,.precedence=100};
	Token *token10 = (Token*)&modulus;

	Number number30 = {.type= NUMBER, .value=30};
	Token *token11 = (Token*)&number30;
	
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=20};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number tempAnswer2 = {.type= NUMBER, .value=120};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type= NUMBER, .value=219};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number tempAnswer4 = {.type= NUMBER, .value=199};
	Token *tempAnsToken4 = (Token*)&tempAnswer4;

	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(20,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(120,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(219,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(199,tempAnsToken4);
	stackPush_Expect(tempAnsToken4,&numStack);
	
	//199%30
	stackPop_ExpectAndReturn(&operatorStack,token10);
	stackPop_ExpectAndReturn(&numStack,token11);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken4);
	createNumberToken_ExpectAndReturn(19,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);

	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20_modulus_30_bitwiseAnd_89(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "100/5*6+99-20%30&89", .startIndex = 0, .length=13};
	
	Number number100 = {.type= NUMBER, .value=100};
	Token *token1 = (Token*)&number100;
	
	Operator divide= {.type= OPERATOR, .id=DIVIDE ,.precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token3 = (Token*)&number5;
	
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token5 = (Token*)&number6;
	
	Operator plus = {.type= OPERATOR, .id=ADD ,.precedence=70};
	Token *token6 = (Token*)&plus;
	
	Number number99 = {.type= NUMBER, .value=99};
	Token *token7 = (Token*)&number99;
	
	Operator minus = {.type= OPERATOR, .id=SUBTRACT ,.precedence=70};
	Token *token8 = (Token*)&minus;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token9 = (Token*)&number20;
	
	Operator modulus = {.type= OPERATOR, .id=MODULUS ,.precedence=100};
	Token *token10 = (Token*)&modulus;

	Number number30 = {.type= NUMBER, .value=30};
	Token *token11 = (Token*)&number30;
	
	Operator bitwiseAnd = {.type= OPERATOR, .id=BITWISE_AND ,.precedence=20};
	Token *token12 = (Token*)&bitwiseAnd;
	
	Number number89 = {.type= NUMBER, .value=89};
	Token *token13 = (Token*)&number89;
	
	//tempAnswer need to initialize value because the stackPush and stackPop is mocked
	Number tempAnswer = {.type= NUMBER, .value=20};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number tempAnswer2 = {.type= NUMBER, .value=120};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type= NUMBER, .value=219};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number tempAnswer4 = {.type= NUMBER, .value=199};
	Token *tempAnsToken4 = (Token*)&tempAnswer4;
	
	Number tempAnswer5 = {.type= NUMBER, .value=19};
	Token *tempAnsToken5 = (Token*)&tempAnswer5;
	
	Number finalAnswer;
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(20,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(120,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(219,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(199,tempAnsToken4);
	stackPush_Expect(tempAnsToken4,&numStack);
	
	//199%30
	stackPop_ExpectAndReturn(&operatorStack,token10);
	stackPop_ExpectAndReturn(&numStack,token11);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken4);
	createNumberToken_ExpectAndReturn(19,tempAnsToken5);
	stackPush_Expect(tempAnsToken5,&numStack);
	
	//19&89
	stackPop_ExpectAndReturn(&operatorStack,token12);
	stackPop_ExpectAndReturn(&numStack,token13);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken5);
	createNumberToken_ExpectAndReturn(17,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}
*/


















