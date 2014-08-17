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
 Test for function evaluate(char* expression)
 Input parameter : 
					1)char *expression

 Using following mock function : 
								1)stringNew()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)textNew()
Using following real function : 
							1)operatorEvaluate(Stack *numberStack , Operator *opeToken);
							2)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
							3)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
							4)calculate(Operator *opeToken, Number *first , Number *second);

All the tests below are running using some mocking functions to test my evaluate(char *expression) running in a correct flow.
The evaluate(char *expression) is the prototype function which will improve to the evaluateExpression(char *expression).
 ********************************************************************************************************************************/	

 void test_evaluate_should_throw_error_if_the_expression_is_null(){
	
	ErrorCode e;
	int check;
	Stack numberStack;
	Stack operatorStack;
	Text *newText;
	
	String tokenizer = {.text = t"NULL"};
	
	createStack_ExpectAndReturn(&numberStack);
	createStack_ExpectAndReturn(&operatorStack);
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
/****************************************************************************
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|	2	|		|		|				|		|		|		|
	|	1	|		|	+	|				|	3	|		|		|
	numberstack		operatorStack			numberstack		operatorStack
			BEFORE									  AFTER
****************************************************************************/
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
/****************************************************************************
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|	4	|		|		|				|		|		|		|
	|	3	|		|	+	|				|		|		|		|
	|	2	|		|	*	|				|	10	|		|		|
	numberstack		operatorStack			numberstack		operatorStack
			BEFORE									  AFTER
****************************************************************************/
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
/****************************************************************************
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|	42	|		|		|				|		|		|		|
	|	43	|		|	#	|				|		|		|		|
	numberstack		operatorStack			numberstack		operatorStack
			BEFORE									  AFTER
****************************************************************************/
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
	getToken_ExpectAndThrow(&tokenizer,ERR_UNKNOWN_INFIX_OPERATOR);
	Try{
		evaluate("43#42");
		 
	 }Catch(e){
		 TEST_ASSERT_EQUAL(ERR_UNKNOWN_INFIX_OPERATOR,e);
	}
}

/****************************************************************************
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|	)	|				|		|		|		|
	|	25  |		|	(	|				|		|		|		|
	numberstack		operatorStack			numberstack		operatorStack
			BEFORE									  AFTER
****************************************************************************/

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

/****************************************************************************
	|		|		|		|				|		|		|		|
	|		|		|		|				|		|		|		|
	|		|		|	)	|				|		|		|		|
	|	50	|		|	-	|				|		|		|		|
	|	3	|		|	*	|				|		|		|		|
	|	20	|		|	(	|				|	10	|		|		|
	numberstack		operatorStack			numberstack		operatorStack
			BEFORE									  AFTER
****************************************************************************/

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




