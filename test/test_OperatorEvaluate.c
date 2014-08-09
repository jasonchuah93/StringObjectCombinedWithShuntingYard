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

void test_operatorEvaluate_60_MODULUS_7(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"60%7"};
	Number number60 = {.type= NUMBER_TOKEN, .value=60};
	Operator modulus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MOD_OP)};
	Number number7 = {.type= NUMBER_TOKEN, .value=7};
	Number number4;
	
	stackPop_ExpectAndReturn(&numberStack,&number7);
	stackPop_ExpectAndReturn(&numberStack,&number60);
	createNumberToken_ExpectAndReturn(4,(Token*)&number4);
	stackPush_Expect(&number4,&numberStack);
	
	operatorEvaluate(&numberStack,&modulus);
}

void test_operatorEvaluate_45_BITWISEAND_54(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"45&54"};
	Number number45 = {.type= NUMBER_TOKEN, .value=45};
	Operator bitwiseAND = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_AND_OP)};
	Number number54 = {.type= NUMBER_TOKEN, .value=54};
	Number number36;
	
	
	stackPop_ExpectAndReturn(&numberStack,&number54);
	stackPop_ExpectAndReturn(&numberStack,&number45);
	createNumberToken_ExpectAndReturn(36,(Token*)&number36);
	stackPush_Expect(&number36,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseAND);
}

void test_operatorEvaluate_56_BITWISEOR_30(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"56|30"};
	Number number56 = {.type= NUMBER_TOKEN, .value=56};
	Operator bitwiseOR = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_OR_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Number number62;
	
	
	stackPop_ExpectAndReturn(&numberStack,&number30);
	stackPop_ExpectAndReturn(&numberStack,&number56);
	createNumberToken_ExpectAndReturn(62,(Token*)&number62);
	stackPush_Expect(&number62,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseOR);
}

void test_operatorEvaluate_56_BITWISEXOR_30(void)
{
	Stack numberStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"56^30"};
	Number number56 = {.type= NUMBER_TOKEN, .value=56};
	Operator bitwiseXOR = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_XOR_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Number number38;
	
	
	stackPop_ExpectAndReturn(&numberStack,&number30);
	stackPop_ExpectAndReturn(&numberStack,&number56);
	createNumberToken_ExpectAndReturn(38,(Token*)&number38);
	stackPush_Expect(&number38,&numberStack);
	
	operatorEvaluate(&numberStack,&bitwiseXOR);
}

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
 
 void test_evaluateAllOperatorOnStack_2_plus_3_plus_4(void){
	Stack numStack;
	Stack operatorStack;
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"2+3+4"};
	
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number4 = {.type= NUMBER_TOKEN, .value=4};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Number number9;
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	//2+3
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number2);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number3);
	createNumberToken_ExpectAndReturn(5,(Token*)&number5);
	stackPush_Expect((Token*)&number5,&numStack);
	
	//5+4
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number4);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number5);
	createNumberToken_ExpectAndReturn(9,(Token*)&number9);
	stackPush_Expect((Token*)&number9,&numStack);
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
	String tokenizer = {.text = t"10+3*9"};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number9 = {.type= NUMBER_TOKEN, .value=9};
	Number number13 = {.type= NUMBER_TOKEN, .value=13};
	Number number117;
	
	//10+3
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number3);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number10);
	createNumberToken_ExpectAndReturn(13,(Token*)&number13);
	stackPush_Expect((Token*)&number13,&numStack);
	
	//13*9
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number9);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number13);
	createNumberToken_ExpectAndReturn(117,(Token*)&number117);
	stackPush_Expect((Token*)&number117,&numStack);
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
	String tokenizer = {.text = t"100/5+60"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number60 = {.type= NUMBER_TOKEN, .value=60};
	Number number20	= {.type= NUMBER_TOKEN, .value=20};
	Number number80 = {.type= NUMBER_TOKEN, .value=80};

	//100/5
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&divide);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number5);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number100);
	createNumberToken_ExpectAndReturn(20,(Token*)&number20);
	stackPush_Expect((Token*)&number20,&numStack);
	
	//20+60
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number60);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	createNumberToken_ExpectAndReturn(80,(Token*)&number80);
	stackPush_Expect((Token*)&number80,&numStack);
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
	String tokenizer = {.text = t"99^66/11+10"};
	
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator bitwiseXOR = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_XOR_OP)};
	Number number66 = {.type= NUMBER_TOKEN, .value=66};
	Operator divide = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number11 = {.type= NUMBER_TOKEN, .value=11};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	Number number33 = {.type= NUMBER_TOKEN, .value=33};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number13 = {.type= NUMBER_TOKEN, .value=13};
	
	
	//99^66
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&bitwiseXOR);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number66);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number99);
	createNumberToken_ExpectAndReturn(33,(Token*)&number33);
	stackPush_Expect((Token*)&number33,&numStack);
	
	//33/11
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&divide);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number11);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number33);
	createNumberToken_ExpectAndReturn(3,(Token*)&number3);
	stackPush_Expect((Token*)&number3,&numStack);
	
	//3+10
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number10);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number3);
	createNumberToken_ExpectAndReturn(13,(Token*)&number13);
	stackPush_Expect((Token*)&number13,&numStack);
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
	String tokenizer = {.text = t"100/5*6+99-20"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide= {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Number number120 = {.type= NUMBER_TOKEN, .value=120};
	Number number219 = {.type= NUMBER_TOKEN, .value=219};
	Number number199 = {.type= NUMBER_TOKEN, .value=199};
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&divide);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number5);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number100);
	createNumberToken_ExpectAndReturn(20,(Token*)&number20);
	stackPush_Expect((Token*)&number20,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number6);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	createNumberToken_ExpectAndReturn(120,(Token*)&number120);
	stackPush_Expect((Token*)&number120,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number99);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number120);
	createNumberToken_ExpectAndReturn(219,(Token*)&number219);
	stackPush_Expect((Token*)&number219,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&minus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number219);
	createNumberToken_ExpectAndReturn(199,(Token*)&number199);
	stackPush_Expect((Token*)&number199,&numStack);
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
	String tokenizer = {.text = t"100/5*6+99-20%30"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide= {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Operator modulus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MOD_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Number number120 = {.type= NUMBER_TOKEN, .value=120};
	Number number219 = {.type= NUMBER_TOKEN, .value=219};
	Number number199 = {.type= NUMBER_TOKEN, .value=199};
	Number number19 = {.type= NUMBER_TOKEN, .value=19};;
	
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&divide);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number5);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number100);
	createNumberToken_ExpectAndReturn(20,(Token*)&number20);
	stackPush_Expect((Token*)&number20,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number6);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	createNumberToken_ExpectAndReturn(120,(Token*)&number120);
	stackPush_Expect((Token*)&number120,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number99);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number120);
	createNumberToken_ExpectAndReturn(219,(Token*)&number219);
	stackPush_Expect((Token*)&number219,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&minus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number219);
	createNumberToken_ExpectAndReturn(199,(Token*)&number199);
	stackPush_Expect((Token*)&number199,&numStack);
	
	//199%30
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&modulus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number30);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number199);
	createNumberToken_ExpectAndReturn(19,(Token*)&number19);
	stackPush_Expect((Token*)&number19,&numStack);
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
	String tokenizer = {.text = t"100/5*6+99-20%30&89"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide= {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Operator modulus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MOD_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Operator bitwiseAND = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_AND_OP)};
	Number number89 = {.type= NUMBER_TOKEN, .value=89};
	Number number120 = {.type= NUMBER_TOKEN, .value=120};
	Number number219 = {.type= NUMBER_TOKEN, .value=219};
	Number number199 = {.type= NUMBER_TOKEN, .value=199};
	Number number19 = {.type= NUMBER_TOKEN, .value=19};
	Number number17 = {.type= NUMBER_TOKEN, .value=17};
	
	
	//100/5
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&divide);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number5);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number100);
	createNumberToken_ExpectAndReturn(20,(Token*)&number20);
	stackPush_Expect((Token*)&number20,&numStack);
	
	//20*6
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number6);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	createNumberToken_ExpectAndReturn(120,(Token*)&number120);
	stackPush_Expect((Token*)&number120,&numStack);
	
	//120+99
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number99);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number120);
	createNumberToken_ExpectAndReturn(219,(Token*)&number219);
	stackPush_Expect((Token*)&number219,&numStack);
	
	//219-20
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&minus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number20);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number219);
	createNumberToken_ExpectAndReturn(199,(Token*)&number199);
	stackPush_Expect((Token*)&number199,&numStack);
	
	//199%30
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&modulus);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number30);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number199);
	createNumberToken_ExpectAndReturn(19,(Token*)&number19);
	stackPush_Expect((Token*)&number19,&numStack);
	
	//19&89
	stackPop_ExpectAndReturn(&operatorStack,(Token*)&bitwiseAND);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number89);
	stackPop_ExpectAndReturn(&numStack,(Token*)&number19);
	createNumberToken_ExpectAndReturn(17,(Token*)&number17);
	stackPush_Expect((Token*)&number17,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	evaluateAllOperatorOnStack(&numStack,&operatorStack);
}



















