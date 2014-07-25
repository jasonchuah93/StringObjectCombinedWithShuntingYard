#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "Text.h"
#include "StringObject.h"
#include "Types.h"
#include "Token.h"
#include "CharSet.h"
//#include "LinkedList.h"
//#include "mock_StringObject.h"
//#include "mock_getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "mock_createNumberToken.h"
//#include "stackForEvaluate.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/*********************************************************************************************************************************
 Test on function evaluate
 Input parameter : 
					1)char *expression

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
Using following real function : 
							1)operatorEvaluate(Stack *numberStack , Operator *opeToken);
							2)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
							3)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
							4)calculate(Operator *opeToken, Number *first , Number *second);
 ********************************************************************************************************************************/	

 void test_shunting_yard_should_return_0_if_the_expression_is_null(){
	
	int check;
	Stack numberStack;
	Stack operatorStack;
	ErrorCode exception;
	Token *token;
	//String tokenizer = {.text = "0", .start = 0, .length=1};
	
	Text *text=textNew("0");
	String *string=stringNew(text);
	//Number number2 = {.type= NUMBER, .value=0};
	//Token *token1 = (Token*)&number2;
	
	//createStack_ExpectAndReturn(&numberStack);
	//createStack_ExpectAndReturn(&operatorStack);
	//stringCreate_ExpectAndReturn(NULL,&tokenizer);
	/*
	Try
	{
		check = evaluate(NULL);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(exception)
	{
		TEST_ASSERT_EQUAL(INVALID_EXPRESSION,exception);
	}
	*/
}

/*
void test_should_return_3_for_1_plus_2(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "1+2", .startIndex = 0, .length=3};
	
	Number number1 = {.type= NUMBER, .value=1};
	Token *token1 = (Token*)&number1;
	
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token3 = (Token*)&number2;
	
	Number answer = {.type= NUMBER, .value=3};
	Token *answerToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("1+2",&tokenizer);
	//Number1
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&dataStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token2,&operatorStack);
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&dataStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&dataStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token1);
	createNumberToken_ExpectAndReturn(3,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d ",check);
}

void test_should_return_6_for_60_divide_10(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};
	
	Number number60 = {.type= NUMBER, .value=60};
	Token *token1 = (Token*)&number60;
	
	Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};
	Token *token2 = (Token*)&divide;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token3 = (Token*)&number10;
	
	Number answer = {.type= NUMBER, .value=6};
	Token *answerToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("60/10",&tokenizer);
	//Number60
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&dataStack);
	
	//Operator token divide
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token2,&operatorStack);
	
	//Number10
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&dataStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack,token2);
	stackPop_ExpectAndReturn(&dataStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token1);
	createNumberToken_ExpectAndReturn(6,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Number tempAnswer = {.type=NUMBER, .value=6};
	Token *tempAnsToken = (Token*)&tempAnswer;

	Number finalAnswer = {.type=NUMBER, .value=10};
	Token *finalAnsToken = (Token*)&finalAnswer;

	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2*3+4",&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Operator token plus cant push in and pop multiply out to evaluate
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(6,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token4,&opeStack);
	
	//Number token 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(10,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);

}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token2 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token4 = (Token*)&multiply;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token6 = (Token*)&plus1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token8 = (Token*)&multiply1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number tempAnswer1 = {.type=NUMBER, .value=12};
	Token *tempAnsToken1 = (Token*)&tempAnswer1;
	
	Number tempAnswer2 = {.type=NUMBER, .value=14};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type=NUMBER, .value=30};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number finalAnswer = {.type=NUMBER, .value=44};
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPush_Expect(token2,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator plus could not push in as multiply has higher
	//precedence .
	//After evaluate multiply,plus still cannot push in as there is
	//one more plus token inside the stack.
	//Thus , plus token inside the stack need to be evaluate first
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,token5);
	stackPop_ExpectAndReturn(&numStack,token3);
	createNumberToken_ExpectAndReturn(12,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken1);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(14,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPush_Expect(token6,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,token7);
	createNumberToken_ExpectAndReturn(30,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(44,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token2 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply1 = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token6 = (Token*)&multiply1;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator plus1 = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token8 = (Token*)&plus1;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Number tempAnswer1 = {.type=NUMBER, .value=6};
	Token *tempAnsToken1 = (Token*)&tempAnswer1;
	
	Number tempAnswer2 = {.type=NUMBER, .value=20};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type=NUMBER, .value=26};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number finalAnswer = {.type=NUMBER, .value=32};
	Token *finalAnsToken = (Token*)&finalAnswer;

	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,token3);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(6,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPush_Expect(token4,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,token5);
	createNumberToken_ExpectAndReturn(20,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken1);
	createNumberToken_ExpectAndReturn(26,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(32,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("2*3+4*5+6");
	TEST_ASSERT_EQUAL(32,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token1 = (Token*)&number2;
	
	Operator OR = {.type= OPERATOR, .id = BITWISE_OR ,.precedence=10};
	Token *token2 = (Token*)&OR;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token3 = (Token*)&number3;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=70};
	Token *token4 = (Token*)&plus;
	
	Number number4 = {.type= NUMBER, .value=4};
	Token *token5 = (Token*)&number4;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=100};
	Token *token6 = (Token*)&multiply;
	
	Number number5 = {.type= NUMBER, .value=5};
	Token *token7 = (Token*)&number5;
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT ,.precedence=70};
	Token *token8 = (Token*)&subtract;
	
	Number number6 = {.type= NUMBER, .value=6};
	Token *token9 = (Token*)&number6;
	
	Operator subtract1 = {.type= OPERATOR, .id = SUBTRACT ,.precedence=70};
	Token *token10 = (Token*)&subtract1;
	
	Number number10 = {.type= NUMBER, .value=10};
	Token *token11 = (Token*)&number10;
	
	Number tempAnswer1 = {.type=NUMBER, .value=20};
	Token *tempAnsToken1 = (Token*)&tempAnswer1;
	
	Number tempAnswer2 = {.type=NUMBER, .value=23};
	Token *tempAnsToken2 = (Token*)&tempAnswer2;
	
	Number tempAnswer3 = {.type=NUMBER, .value=17};
	Token *tempAnsToken3 = (Token*)&tempAnswer3;
	
	Number tempAnswer4 = {.type=NUMBER, .value=7};
	Token *tempAnsToken4 = (Token*)&tempAnswer4;
	
	Number finalAnswer = {.type=NUMBER, .value=7};
	Token *finalAnsToken = (Token*)&finalAnswer;
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("2|3+4*5-6-10",&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&numStack);
	
	//Token operator bitwize OR
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,0);
	isOperator_ExpectAndReturn(token2,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token2,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,1);
	stackPush_Expect(token3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,0);
	isOperator_ExpectAndReturn(token4,1);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPush_Expect(token2,&opeStack);
	stackPush_Expect(token4,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,1);
	stackPush_Expect(token5,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,0);
	isOperator_ExpectAndReturn(token6,1);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPush_Expect(token4,&opeStack);
	stackPush_Expect(token6,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,1);
	stackPush_Expect(token7,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token8);
	isNumber_ExpectAndReturn(token8,0);
	isOperator_ExpectAndReturn(token8,1);
	stackPop_ExpectAndReturn(&opeStack,token6);
	stackPop_ExpectAndReturn(&numStack,token7);
	stackPop_ExpectAndReturn(&numStack,token5);
	createNumberToken_ExpectAndReturn(20,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token4);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken1);
	stackPop_ExpectAndReturn(&numStack,token3);
	createNumberToken_ExpectAndReturn(23,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPush_Expect(token2,&opeStack);
	stackPush_Expect(token8,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,token9);
	isNumber_ExpectAndReturn(token9,1);
	stackPush_Expect(token9,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token10);
	isNumber_ExpectAndReturn(token10,0);
	isOperator_ExpectAndReturn(token10,1);
	stackPop_ExpectAndReturn(&opeStack,token8);
	stackPop_ExpectAndReturn(&numStack,token9);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken2);
	createNumberToken_ExpectAndReturn(17,tempAnsToken3);
	stackPush_Expect(tempAnsToken3,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPush_Expect(token2,&opeStack);
	stackPush_Expect(token10,&opeStack);
	
	//Token	number 10 
	getToken_ExpectAndReturn(&tokenizer,token11);
	isNumber_ExpectAndReturn(token11,1);
	stackPush_Expect(token11,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,token10);
	stackPop_ExpectAndReturn(&numStack,token11);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken3);
	createNumberToken_ExpectAndReturn(7,tempAnsToken4);
	stackPush_Expect(tempAnsToken4,&numStack);
	stackPop_ExpectAndReturn(&opeStack,token2);
	stackPop_ExpectAndReturn(&numStack,tempAnsToken4);
	stackPop_ExpectAndReturn(&numStack,token1);
	createNumberToken_ExpectAndReturn(7,finalAnsToken);
	stackPush_Expect(finalAnsToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,finalAnsToken); 
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("2|3+4*5-6-10");
	TEST_ASSERT_EQUAL(7,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator(void){
	
	Stack dataStack;
	Stack operatorStack;
	int check;
	Error e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "43)42", .startIndex = 0};
	
	Number number43 = {.type= NUMBER, .value=43};
	Token *token1 = (Token*)&number43;
	
	Operator hashtag = {.type= OPERATOR, .id=RIGHT_PARENTHESIS, .precedence=50};
	Token *token2 = (Token*)&hashtag;
	
	Number number42 = {.type= NUMBER, .value=42};
	Token *token3 = (Token*)&number42;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("43#42",&tokenizer);
	//44
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,1);
	stackPush_Expect(token1,&dataStack);
	//HASHTAG
	getToken_ExpectAndThrow(&tokenizer,UNKNOWN_OPERATOR);
	
	Try{
		evaluate("43#42");
		 TEST_FAIL_MESSAGE("Should throw ERR_INVALID_OPERATOR");
	 }Catch(e){
		 TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,e);
	 }
}

void xtest_should_evaluate_left_parenthesis_2_right_parenthesis(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(2)", .startIndex = 0, .length = 3};
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};
	Token *token1 = (Token*)&leftBracket;

	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};
	Token *token3 = (Token*)&rightBracket;	
	
	Number answer = {.type= NUMBER, .value=2};
	Token *answerToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("(2)",&tokenizer);
	
	//Operator token left parenthesis
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL); //If operator stack is null,
	stackPush_Expect(token1,&operatorStack);	  //then push a operator token inside
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&dataStack);
	
	//Operator token right parenthesis
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	stackPop_ExpectAndReturn(&operatorStack,token1); //Operator stack has token1 inside
	stackPop_ExpectAndReturn(&dataStack,token2); //Once left and right bracket is detected, pop the token1 and number token and evaluate
	createNumberToken_ExpectAndReturn(2,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
	
}

void xtest_should_evaluate_left_parenthesis_22_right_parenthesis(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(22)", .startIndex = 0, .length = 3};
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};
	Token *token1 = (Token*)&leftBracket;

	Number number22 = {.type= NUMBER, .value=22};
	Token *token2 = (Token*)&number22;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};
	Token *token3 = (Token*)&rightBracket;	
	
	Number answer = {.type= NUMBER, .value=22};
	Token *answerToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("(22)",&tokenizer);
	
	//Operator token left parenthesis
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token1,&operatorStack);
	
	//Number22
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&dataStack);
	
	//Operator token right parenthesis
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	stackPop_ExpectAndReturn(&operatorStack,token1);
	stackPop_ExpectAndReturn(&dataStack,token2);
	createNumberToken_ExpectAndReturn(22,answerToken);
	stackPush_Expect(answerToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,answerToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(22)");
	TEST_ASSERT_EQUAL(22,check);
	printf("Answer : %d ",check);
	
}

void test_left_bracket_2_plus_3_right_bracket(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(2+3)", .startIndex = 0, .length = 5};
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};
	Token *token1 = (Token*)&leftBracket;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Operator plus = {.type= OPERATOR, .id = ADD ,.precedence=60};
	Token *token3 = (Token*)&plus;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};
	Token *token5 = (Token*)&rightBracket;
	
	Number answer = {.type= NUMBER, .value=5};
	Token *ansToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("(2+3)",&tokenizer);
	//(
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token1,&operatorStack);
	//2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&dataStack);
	//+
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	stackPop_ExpectAndReturn(&operatorStack,token1);
	stackPush_Expect(token1,&operatorStack);
	stackPush_Expect(token3,&operatorStack);
	//3
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&dataStack);
	//)
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	stackPop_ExpectAndReturn(&operatorStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token4);
	stackPop_ExpectAndReturn(&dataStack,token2);
	createNumberToken_ExpectAndReturn(5,ansToken);
	stackPush_Expect(ansToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,ansToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(2+3)");
	TEST_ASSERT_EQUAL(5,check);
	printf("Answer : %d ",check);
}

void test_left_bracket_20_multiply_3_subtract_50_right_bracket(void){
	Stack dataStack;
	Stack operatorStack;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(20*3-50)", .startIndex = 0, .length = 7};
	
	Operator leftBracket = {.type= OPERATOR, .id = LEFT_PARENTHESIS ,.precedence=2};
	Token *token1 = (Token*)&leftBracket;
	
	Number number20 = {.type= NUMBER, .value=20};
	Token *token2 = (Token*)&number20;
	
	Operator multiply = {.type= OPERATOR, .id = MULTIPLY ,.precedence=70};
	Token *token3 = (Token*)&multiply;
	
	Number number3 = {.type= NUMBER, .value=3};
	Token *token4 = (Token*)&number3;
	
	Operator minus = {.type= OPERATOR, .id = SUBTRACT ,.precedence=60};
	Token *token5 = (Token*)&minus;
	
	Number number50 = {.type= NUMBER, .value=50};
	Token *token6 = (Token*)&number50;
	
	Operator rightBracket = {.type= OPERATOR, .id = RIGHT_PARENTHESIS ,.precedence=1};
	Token *token7 = (Token*)&rightBracket;
	
	Number tempAnswer = {.type= NUMBER, .value=60};
	Token *tempAnsToken = (Token*)&tempAnswer;
	
	Number answer = {.type= NUMBER, .value=10};
	Token *ansToken = (Token*)&answer;
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	stringCreate_ExpectAndReturn("(20*3-50)",&tokenizer);
	//(
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(token1,&operatorStack);
	//20
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&dataStack);
	//*
	getToken_ExpectAndReturn(&tokenizer,token3);
	isNumber_ExpectAndReturn(token3,0);
	isOperator_ExpectAndReturn(token3,1);
	stackPop_ExpectAndReturn(&operatorStack,token1);
	stackPush_Expect(token1,&operatorStack);
	stackPush_Expect(token3,&operatorStack);
	//3
	getToken_ExpectAndReturn(&tokenizer,token4);
	isNumber_ExpectAndReturn(token4,1);
	stackPush_Expect(token4,&dataStack);
	//-
	getToken_ExpectAndReturn(&tokenizer,token5);
	isNumber_ExpectAndReturn(token5,0);
	isOperator_ExpectAndReturn(token5,1);
	stackPop_ExpectAndReturn(&operatorStack,token3);
	stackPop_ExpectAndReturn(&dataStack,token4);
	stackPop_ExpectAndReturn(&dataStack,token2);
	createNumberToken_ExpectAndReturn(60,tempAnsToken);
	stackPush_Expect(tempAnsToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,token1);
	stackPush_Expect(token1,&operatorStack);
	stackPush_Expect(token5,&operatorStack);
	//50
	getToken_ExpectAndReturn(&tokenizer,token6);
	isNumber_ExpectAndReturn(token6,1);
	stackPush_Expect(token6,&dataStack);
	// )
	getToken_ExpectAndReturn(&tokenizer,token7);
	isNumber_ExpectAndReturn(token7,0);
	isOperator_ExpectAndReturn(token7,1);
	stackPop_ExpectAndReturn(&operatorStack,token5);
	stackPop_ExpectAndReturn(&dataStack,token6);
	stackPop_ExpectAndReturn(&dataStack,tempAnsToken);
	createNumberToken_ExpectAndReturn(10,ansToken);
	stackPush_Expect(ansToken,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,ansToken);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(20*3-50)");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);
}

void test_logic_not_12_SHOULD_RETURN_0(void){
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "!12", .startIndex = 0, .length = 2 };
	
	Operator logicNot = {.type= OPERATOR, .id = LOGIC_NOT, .precedence=80};
	Token *token1 = (Token*)&logicNot;
	
	Number number12 = {.type= NUMBER, .value=12};
	Token *token2 = (Token*)&number12;
	
	Number answer = {.type=NUMBER, .value=0};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("!12",&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token1,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&opeStack,token1);
	stackPop_ExpectAndReturn(&numStack,token2);
	stackPop_ExpectAndReturn(&numStack,NULL);
	createNumberToken_ExpectAndReturn(0,ansToken);
	stackPush_Expect(ansToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPop_ExpectAndReturn(&numStack,ansToken);
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("!12");
	TEST_ASSERT_EQUAL(0,check);
	printf("Answer : %d ",check);

}

void test_NEGATIVE_2_SHOULD_RETURN_NEGATIVE_2(void){
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "-2", .startIndex = 0, .length = 2 };
	
	Operator subtract = {.type= OPERATOR, .id = SUBTRACT, .precedence=60};
	Token *token1 = (Token*)&subtract;
	
	Number number2 = {.type= NUMBER, .value=2};
	Token *token2 = (Token*)&number2;
	
	Number answer = {.type=NUMBER, .value=-2};
	Token *ansToken = (Token*)&answer;
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	stringCreate_ExpectAndReturn("-2",&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,token1);
	isNumber_ExpectAndReturn(token1,0);
	isOperator_ExpectAndReturn(token1,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect(token1,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,token2);
	isNumber_ExpectAndReturn(token2,1);
	stackPush_Expect(token2,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&opeStack,token1);
	stackPop_ExpectAndReturn(&numStack,token2);
	stackPop_ExpectAndReturn(&numStack,NULL);
	createNumberToken_ExpectAndReturn(-2,ansToken);
	stackPush_Expect(ansToken,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPop_ExpectAndReturn(&numStack,ansToken);
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("-2");
	TEST_ASSERT_EQUAL(-2,check);
	printf("Answer : %d ",check);

}
*/
