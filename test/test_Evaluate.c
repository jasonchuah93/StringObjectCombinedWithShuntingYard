#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "mock_Text.h"
#include "mock_StringObject.h"
#include "Types.h"
#include "Token.h"
#include "mock_getToken.h"
#include "CharSet.h"
#include "LinkedList.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "mock_createNumberToken.h"
#include "stackForEvaluate.h"
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
/*
 void test_evaluate_should_throw_error_if_the_expression_is_null(){
	
	ErrorCode e;
	int check;
	Stack numberStack;
	Stack operatorStack;
	Text *newText;
	
	String tokenizer = {.text = t"NULL"};
	
	createStack_ExpectAndReturn(&numberStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn(NULL,newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	Try
	{
		check=evaluate(NULL);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT ,e);
	}
	
	
}

void test_should_return_3_for_1_plus_2(void){
	
	int check;
	Stack numberStack;
	Stack operatorStack;
	Text *newText;
	
	String tokenizer = {.text = t"1+2"};
	
	Number number1 = {.type= NUMBER_TOKEN, .value=1};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};	
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Operator plus =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	createStack_ExpectAndReturn(&numberStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("1+2",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Number1
	getToken_ExpectAndReturn(&tokenizer, (Token *)&number1);
	isNumber_ExpectAndReturn((Token *)&number1, 1);
	stackPush_Expect((Token *)&number1, &numberStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer, (Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus, 0);
	isOperator_ExpectAndReturn((Token *)&plus, 1);
	stackPop_ExpectAndReturn(&operatorStack, NULL);
	stackPush_Expect((Token *)&plus, &operatorStack);
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer, (Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2, 1);
	stackPush_Expect((Token *)&number2, &numberStack);
	getToken_ExpectAndReturn(&tokenizer, NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack, (Token *)&plus);
	stackPop_ExpectAndReturn(&numberStack, (Token *)&number2);
	stackPop_ExpectAndReturn(&numberStack, (Token *)&number1);
	createNumberToken_ExpectAndReturn(3, (Token *)&number3);
	stackPush_Expect((Token *)&number3, &numberStack);
	stackPop_ExpectAndReturn(&operatorStack, NULL);
	
	stackPop_ExpectAndReturn(&numberStack, (Token *)&number3);
	destroyStack_Expect(&numberStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3, check);
	printf("Answer : %d ",check);
}	

void test_should_return_6_for_60_divide_10(void){
	
	int check;
	Stack numberStack;
	Stack operatorStack;
	Text *newText;
	
	String tokenizer = {.text = t"60/10"};
	
	Number number60 = {.type= NUMBER_TOKEN, .value=60};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};	
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator divide =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	
	createStack_ExpectAndReturn(&numberStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("60/10",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Number60
	getToken_ExpectAndReturn(&tokenizer, (Token *)&number60);
	isNumber_ExpectAndReturn((Token *)&number60, 1);
	stackPush_Expect((Token *)&number60, &numberStack);
	
	//Operator token divide
	getToken_ExpectAndReturn(&tokenizer,(Token *)&divide);
	isNumber_ExpectAndReturn((Token *)&divide,0);
	isOperator_ExpectAndReturn((Token *)&divide,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect((Token *)&divide,&operatorStack);
	
	//Number10
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number10);
	isNumber_ExpectAndReturn((Token *)&number10,1);
	stackPush_Expect((Token *)&number10,&numberStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Calculation
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&divide);
	stackPop_ExpectAndReturn(&numberStack,(Token *)&number10);
	stackPop_ExpectAndReturn(&numberStack,(Token *)&number60);
	createNumberToken_ExpectAndReturn(6,(Token *)&number6);
	stackPush_Expect((Token *)&number6,&numberStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&numberStack,(Token *)&number6);
	destroyStack_Expect(&numberStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6, check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	
	int check;
	Stack numStack;
	Stack operatorStack;
	Text *newText;
	
	String tokenizer = {.text = t"2*3+4"};
	
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number6 = {.type=NUMBER_TOKEN, .value=6};
	Number number4 = {.type= NUMBER_TOKEN, .value=4};
	Number number10 = {.type=NUMBER_TOKEN, .value=10};
	
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("2*3+4",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Number token 2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&numStack);
	
	//Operator token multiply
	getToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	isNumber_ExpectAndReturn((Token *)&multiply,0);
	isOperator_ExpectAndReturn((Token *)&multiply,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect((Token *)&multiply,&operatorStack);
	
	//Number token 3
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	isNumber_ExpectAndReturn((Token *)&number3,1);
	stackPush_Expect((Token *)&number3,&numStack);
	
	//Operator token plus cant push in and pop multiply out to evaluate
	getToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus,0);
	isOperator_ExpectAndReturn((Token *)&plus,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number3);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number2);
	createNumberToken_ExpectAndReturn(6,(Token *)&number6);
	stackPush_Expect((Token *)&number6,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect((Token *)&plus,&operatorStack);
	
	//Number token 4
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	isNumber_ExpectAndReturn((Token *)&number4,1);
	stackPush_Expect((Token *)&number4,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);

	//Evaluate expression
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number4);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number6);
	createNumberToken_ExpectAndReturn(10,(Token *)&number10);
	stackPush_Expect((Token *)&number10,&numStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,(Token *)&number10); 
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);
	
}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	
	int check;
	Stack numStack;
	Stack opeStack;
	Text *newText;
	
	String tokenizer = {.text = t"2+3*4+5*6"};
	
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number4 = {.type= NUMBER_TOKEN, .value=4};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Number number12 = {.type=NUMBER_TOKEN, .value=12};
	Number number14 = {.type=NUMBER_TOKEN, .value=14};
	Number number30 = {.type=NUMBER_TOKEN, .value=30};
	Number number44 = {.type=NUMBER_TOKEN, .value=44};
	
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	textNew_ExpectAndReturn("2+3*4+5*6",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&numStack);
	
	//Operator token plus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus,0);
	isOperator_ExpectAndReturn((Token *)&plus,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect((Token *)&plus,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	isNumber_ExpectAndReturn((Token *)&number3,1);
	stackPush_Expect((Token *)&number3,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	isNumber_ExpectAndReturn((Token *)&multiply,0);
	isOperator_ExpectAndReturn((Token *)&multiply,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPush_Expect((Token *)&plus,&opeStack);
	stackPush_Expect((Token *)&multiply,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	isNumber_ExpectAndReturn((Token *)&number4,1);
	stackPush_Expect((Token *)&number4,&numStack);
	
	//Token operator plus could not push in as multiply has higher
	//precedence .
	//After evaluate multiply,plus still cannot push in as there is
	//one more plus token inside the stack.
	//Thus , plus token inside the stack need to be evaluate first
	getToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus,0);
	isOperator_ExpectAndReturn((Token *)&plus,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number4);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number3);
	createNumberToken_ExpectAndReturn(12,(Token *)&number12);
	stackPush_Expect((Token *)&number12,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number12);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number2);
	createNumberToken_ExpectAndReturn(14,(Token *)&number14);
	stackPush_Expect((Token *)&number14,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect((Token *)&plus,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number5);
	isNumber_ExpectAndReturn((Token *)&number5,1);
	stackPush_Expect((Token *)&number5,&numStack);
	
	//Token operator multiply
	getToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	isNumber_ExpectAndReturn((Token *)&multiply,0);
	isOperator_ExpectAndReturn((Token *)&multiply,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPush_Expect((Token *)&plus,&opeStack);
	stackPush_Expect((Token *)&multiply,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number6);
	isNumber_ExpectAndReturn((Token *)&number6,1);
	stackPush_Expect((Token *)&number6,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,(Token *)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number6);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number5);
	createNumberToken_ExpectAndReturn(30,(Token *)&number30);
	stackPush_Expect((Token *)&number30,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number30);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number14);
	createNumberToken_ExpectAndReturn(44,(Token *)&number44);
	stackPush_Expect((Token *)&number44,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,(Token *)&number44); 
	
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	
	int check;
	Stack numStack;
	Stack opeStack;
	Text *newText;
	
	String tokenizer = {.text = t"2|3+4*5-6-10"};
	
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Number number4 = {.type= NUMBER_TOKEN, .value=4};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	Number number20 = {.type=NUMBER_TOKEN, .value=20};
	Number number23 = {.type=NUMBER_TOKEN, .value=23};
	Number number17  = {.type=NUMBER_TOKEN, .value=17};
	Number number7 = {.type=NUMBER_TOKEN, .value=7};
	
	Operator OR = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_OR_OP) };
	Operator plus = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(ADD_OP)};	
	Operator multiply = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(MUL_OP)};
	Operator subtract = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	textNew_ExpectAndReturn("2|3+4*5-6-10",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&numStack);
	
	//Token operator bitwize OR
	getToken_ExpectAndReturn(&tokenizer,(Token *)&OR);
	isNumber_ExpectAndReturn((Token *)&OR,0);
	isOperator_ExpectAndReturn((Token *)&OR,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect((Token *)&OR,&opeStack);
	
	//Token number 3
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	isNumber_ExpectAndReturn((Token *)&number3,1);
	stackPush_Expect((Token *)&number3,&numStack);
	
	//Token operator plus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus,0);
	isOperator_ExpectAndReturn((Token *)&plus,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&OR);
	stackPush_Expect((Token *)&OR,&opeStack);
	stackPush_Expect((Token *)&plus,&opeStack);
	
	//Token number 4
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number4);
	isNumber_ExpectAndReturn((Token *)&number4,1);
	stackPush_Expect((Token *)&number4,&numStack);
	
	//Token operator multiply 
	getToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	isNumber_ExpectAndReturn((Token *)&multiply,0);
	isOperator_ExpectAndReturn((Token *)&multiply,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPush_Expect((Token *)&plus,&opeStack);
	stackPush_Expect((Token *)&multiply,&opeStack);
	
	//Token number 5
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number5);
	isNumber_ExpectAndReturn((Token *)&number5,1);
	stackPush_Expect((Token *)&number5,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&subtract);
	isNumber_ExpectAndReturn((Token *)&subtract,0);
	isOperator_ExpectAndReturn((Token *)&subtract,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&multiply);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number5);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number4);
	createNumberToken_ExpectAndReturn(20,(Token *)&number20);
	stackPush_Expect((Token *)&number20,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&plus);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number20);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number3);
	createNumberToken_ExpectAndReturn(23,(Token *)&number23);
	stackPush_Expect((Token *)&number23,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&OR);
	stackPush_Expect((Token *)&OR,&opeStack);
	stackPush_Expect((Token *)&subtract,&opeStack);
	
	//Token number 6
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number6);
	isNumber_ExpectAndReturn((Token *)&number6,1);
	stackPush_Expect((Token *)&number6,&numStack);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&subtract);
	isNumber_ExpectAndReturn((Token *)&subtract,0);
	isOperator_ExpectAndReturn((Token *)&subtract,1);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&subtract);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number6);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number23);
	createNumberToken_ExpectAndReturn(17,(Token *)&number17);
	stackPush_Expect((Token *)&number17,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&OR);
	stackPush_Expect((Token *)&OR,&opeStack);
	stackPush_Expect((Token *)&subtract,&opeStack);
	
	//Token	number 10 
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number10);
	isNumber_ExpectAndReturn((Token *)&number10,1);
	stackPush_Expect((Token *)&number10,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate expression
	stackPop_ExpectAndReturn(&opeStack,(Token *)&subtract);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number10);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number17);
	createNumberToken_ExpectAndReturn(7,(Token *)&number7);
	stackPush_Expect((Token *)&number7,&numStack);
	stackPop_ExpectAndReturn(&opeStack,(Token *)&OR);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number7);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number2);
	createNumberToken_ExpectAndReturn(7,(Token *)&number7);
	stackPush_Expect((Token *)&number7,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	
	stackPop_ExpectAndReturn(&numStack,(Token *)&number7); 
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
	ErrorCode e;
	Text *newText;
	
	String tokenizer = {.text = t"43#42"};
	
	Number number43 = {.type= NUMBER_TOKEN, .value=43};
	Number number42 = {.type= NUMBER_TOKEN, .value=42};
	Operator hashtag = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(HASH_OP) };
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("43#42",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//44
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number43);
	isNumber_ExpectAndReturn((Token *)&number43,1);
	stackPush_Expect((Token *)&number43,&dataStack);
	//HASHTAG
	getToken_ExpectAndThrow(&tokenizer,UNKNOWN_OPERATOR);
	Try{
		evaluate("43#42");
		 TEST_FAIL_MESSAGE("Should throw ERR_INVALID_OPERATOR");
	 }Catch(e){
		 TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,e);
		 
	 }
}

void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){
	
	Stack dataStack;
	Stack operatorStack;
	int check;
	Text *newText;
	
	String tokenizer = {.text = t"(2)"};
	
	Operator leftBracket = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Operator rightBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("(2)",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Operator token left parenthesis
	getToken_ExpectAndReturn(&tokenizer,(Token *)&leftBracket);
	isNumber_ExpectAndReturn((Token *)&leftBracket,0);
	isOperator_ExpectAndReturn((Token *)&leftBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL); //If operator stack is null,
	stackPush_Expect((Token *)&leftBracket,&operatorStack);	  //then push a operator token inside
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&dataStack);
	
	//Operator token right parenthesis
	getToken_ExpectAndReturn(&tokenizer,(Token *)&rightBracket);
	isNumber_ExpectAndReturn((Token *)&rightBracket,0);
	isOperator_ExpectAndReturn((Token *)&rightBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&leftBracket); //Operator stack has token1 inside
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number2); //Once left and right bracket is detected, pop the token1 and number token and evaluate
	createNumberToken_ExpectAndReturn(2,(Token *)&number2);
	stackPush_Expect((Token *)&number2,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number2);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_left_parenthesis_25_right_parenthesis(void){
	
	Stack dataStack;
	Stack operatorStack;
	int check;
	Text *newText;
	
	String tokenizer = {.text = t"(25)"};
	
	Operator leftBracket = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number25 = {.type= NUMBER_TOKEN, .value=25};
	Operator rightBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("(25)",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Operator token left parenthesis
	getToken_ExpectAndReturn(&tokenizer,(Token *)&leftBracket);
	isNumber_ExpectAndReturn((Token *)&leftBracket,0);
	isOperator_ExpectAndReturn((Token *)&leftBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL); //If operator stack is null,
	stackPush_Expect((Token *)&leftBracket,&operatorStack);	  //then push a operator token inside
	
	//Number2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number25);
	isNumber_ExpectAndReturn((Token *)&number25,1);
	stackPush_Expect((Token *)&number25,&dataStack);
	
	//Operator token right parenthesis
	getToken_ExpectAndReturn(&tokenizer,(Token *)&rightBracket);
	isNumber_ExpectAndReturn((Token *)&rightBracket,0);
	isOperator_ExpectAndReturn((Token *)&rightBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&leftBracket); //Operator stack has token1 inside
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number25); //Once left and right bracket is detected, pop the token1 and number token and evaluate
	createNumberToken_ExpectAndReturn(25,(Token *)&number25);
	stackPush_Expect((Token *)&number25,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number25);
	destroyStack_Expect(&dataStack);
	destroyStack_Expect(&operatorStack);
	
	check=evaluate("(25)");
	TEST_ASSERT_EQUAL(25,check);
	printf("Answer : %d ",check);
}

void test_left_bracket_2_plus_3_right_bracket(void){
	
	Stack dataStack;
	Stack operatorStack;
	int check;
	Text *newText;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"(2+3)"};
	
	Operator leftBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Operator plus = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(ADD_OP)};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Operator rightBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("(2+3)",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//(
	getToken_ExpectAndReturn(&tokenizer,(Token *)&leftBracket);
	isNumber_ExpectAndReturn((Token *)&leftBracket,0);
	isOperator_ExpectAndReturn((Token *)&leftBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect((Token *)&leftBracket,&operatorStack);
	//2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&dataStack);
	//+
	getToken_ExpectAndReturn(&tokenizer,(Token *)&plus);
	isNumber_ExpectAndReturn((Token *)&plus,0);
	isOperator_ExpectAndReturn((Token *)&plus,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&leftBracket);
	stackPush_Expect((Token *)&leftBracket,&operatorStack);
	stackPush_Expect((Token *)&plus,&operatorStack);
	//3
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	isNumber_ExpectAndReturn((Token *)&number3,1);
	stackPush_Expect((Token *)&number3,&dataStack);
	//)
	getToken_ExpectAndReturn(&tokenizer,(Token *)&rightBracket);
	isNumber_ExpectAndReturn((Token *)&rightBracket,0);
	isOperator_ExpectAndReturn((Token *)&rightBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&plus);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number3);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number2);
	createNumberToken_ExpectAndReturn(5,(Token *)&number5);
	stackPush_Expect((Token *)&number5,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number5);
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
	Text *newText;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"(20*3-50)"};
	
	Operator leftBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number50 = {.type= NUMBER_TOKEN, .value=50};
	Operator rightBracket = {.type= OPERATOR_TOKEN,.info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	Number number60 = {.type= NUMBER_TOKEN, .value=60};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	
	createStack_ExpectAndReturn(&dataStack);
	createStack_ExpectAndReturn(&operatorStack);
	textNew_ExpectAndReturn("(20*3-50)",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	//(
	getToken_ExpectAndReturn(&tokenizer,(Token *)&leftBracket);
	isNumber_ExpectAndReturn((Token *)&leftBracket,0);
	isOperator_ExpectAndReturn((Token *)&leftBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect((Token *)&leftBracket,&operatorStack);
	//20
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number20);
	isNumber_ExpectAndReturn((Token *)&number20,1);
	stackPush_Expect((Token *)&number20,&dataStack);
	//*
	getToken_ExpectAndReturn(&tokenizer,(Token *)&multiply);
	isNumber_ExpectAndReturn((Token *)&multiply,0);
	isOperator_ExpectAndReturn((Token *)&multiply,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&leftBracket);
	stackPush_Expect((Token *)&leftBracket,&operatorStack);
	stackPush_Expect((Token *)&multiply,&operatorStack);
	//3
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number3);
	isNumber_ExpectAndReturn((Token *)&number3,1);
	stackPush_Expect((Token *)&number3,&dataStack);
	//-
	getToken_ExpectAndReturn(&tokenizer,(Token *)&minus);
	isNumber_ExpectAndReturn((Token *)&minus,0);
	isOperator_ExpectAndReturn((Token *)&minus,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&multiply);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number3);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number20);
	createNumberToken_ExpectAndReturn(60,(Token *)&number60);
	stackPush_Expect((Token *)&number60,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&leftBracket);
	stackPush_Expect((Token *)&leftBracket,&operatorStack);
	stackPush_Expect((Token *)&minus,&operatorStack);
	//50
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number50);
	isNumber_ExpectAndReturn((Token *)&number50,1);
	stackPush_Expect((Token *)&number50,&dataStack);
	// )
	getToken_ExpectAndReturn(&tokenizer,(Token *)&rightBracket);
	isNumber_ExpectAndReturn((Token *)&rightBracket,0);
	isOperator_ExpectAndReturn((Token *)&rightBracket,1);
	stackPop_ExpectAndReturn(&operatorStack,(Token *)&minus);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number50);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number60);
	createNumberToken_ExpectAndReturn(10,(Token *)&number10);
	stackPush_Expect((Token *)&number10,&dataStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPop_ExpectAndReturn(&dataStack,(Token *)&number10);
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
	Text *newText;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"!12"};
	
	Operator logicNot = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(LOGICAL_NOT_OP)};
	Number number12 = {.type= NUMBER_TOKEN, .value=12};
	Number number0 = {.type=NUMBER_TOKEN, .value=0};
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	textNew_ExpectAndReturn("!12",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&logicNot);
	isNumber_ExpectAndReturn((Token *)&logicNot,0);
	isOperator_ExpectAndReturn((Token *)&logicNot,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect((Token *)&logicNot,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number12);
	isNumber_ExpectAndReturn((Token *)&number12,1);
	stackPush_Expect((Token *)&number12,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&opeStack,(Token *)&logicNot);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number12);
	stackPop_ExpectAndReturn(&numStack,NULL);
	createNumberToken_ExpectAndReturn(0,(Token *)&number0);
	stackPush_Expect((Token *)&number0,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number0);
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
	Text *newText;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"-2"};
	
	Operator subtract = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MINUS_OP)};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number negNum2 = {.type=NUMBER_TOKEN, .value=-2};
	
	//Evaluate the expression
	createStack_ExpectAndReturn(&numStack);
	createStack_ExpectAndReturn(&opeStack);
	textNew_ExpectAndReturn("-2",newText);
	stringNew_ExpectAndReturn(newText,&tokenizer);
	
	//Token operator minus
	getToken_ExpectAndReturn(&tokenizer,(Token *)&subtract);
	isNumber_ExpectAndReturn((Token *)&subtract,0);
	isOperator_ExpectAndReturn((Token *)&subtract,1);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPush_Expect((Token *)&subtract,&opeStack);
	
	//Token number 2
	getToken_ExpectAndReturn(&tokenizer,(Token *)&number2);
	isNumber_ExpectAndReturn((Token *)&number2,1);
	stackPush_Expect((Token *)&number2,&numStack);
	getToken_ExpectAndReturn(&tokenizer,NULL);
	
	//Evaluate
	stackPop_ExpectAndReturn(&opeStack,(Token *)&subtract);
	stackPop_ExpectAndReturn(&numStack,(Token *)&number2);
	stackPop_ExpectAndReturn(&numStack,NULL);
	createNumberToken_ExpectAndReturn(-2,(Token *)&negNum2);
	stackPush_Expect((Token *)&negNum2,&numStack);
	stackPop_ExpectAndReturn(&opeStack,NULL);
	stackPop_ExpectAndReturn(&numStack,(Token *)&negNum2);
	destroyStack_Expect(&numStack);
	destroyStack_Expect(&opeStack);
	
	check=evaluate("-2");
	TEST_ASSERT_EQUAL(-2,check);
	printf("Answer : %d ",check);

}
*/