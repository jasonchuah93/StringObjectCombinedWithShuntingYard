#include "unity.h"
#include "Evaluate.h"
#include "Token.h"
#include "getToken.h"
#include "Text.h"
#include "StringObject.h"
#include "CharSet.h"
#include "Stack.h"
#include "LinkedList.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h"
#include "stackForEvaluate.h"
#include "CustomTypeAssert.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void) {}
void tearDown(void) {}

/*********************************************************************************************************************************
 Test on function evaluateExpression(char *expression)
 Input parameter : 
					1)char *expression

 Using following real function : 
								1)getToken()
								2)stackPop()  
								3)stackPush()
								4)createNumberToken()
								5)operatorEvaluate(Stack *numberStack , Operator *opeToken);
								6)evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack);
								7)tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack);
								8)calculate(Operator *opeToken, Number *first , Number *second);
								9)textNew(char *expression)
								10)stringNew(Text *text)

This test files will doing all the tests request by Dr. Poh using the latest evaluate function which is 
evaluateExpression(char *expression)

********************************************************************************************************************************/

void test_evaluate_should_throw_error_if_the_expression_is_null(){
	
	ErrorCode e;
	int check;
	Try
	{
		check=evaluateExpression(NULL);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_NO_ARGUMENT ,e);
	}
}

void test_should_evaluate_1_plus_2(void){
	int check;
	check=evaluateExpression("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d \n",check);
}

/*
void test_evaluate_5(void){
	int check;
	check=evaluateExpression("5");
	
	TEST_ASSERT_EQUAL(5,check);
	printf("Answer : %d \n",check);
}

void test_evaluate_negative_2(void){
	int check;
	check=evaluateExpression("-2");
	
	TEST_ASSERT_EQUAL(-2,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_negative_60(void){
	int check;
	
	check=evaluateExpression("--60");
	TEST_ASSERT_EQUAL(60,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_LOGICAL_NOT_10(void){
	int check;
	check=evaluateExpression("!10");
	
	TEST_ASSERT_EQUAL(0,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_BITWISE_NOT_5(void){
	int check;
	check=evaluateExpression("~5");
	
	TEST_ASSERT_EQUAL(-6,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_100(void){
	int check;
	check=evaluateExpression("+100");
	
	TEST_ASSERT_EQUAL(100,check);
	printf("Answer : %d \n",check);
}


void test_should_evaluate_negative_negative_3(void){
	int check;
	check=evaluateExpression("--3");
	
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_positive_30(void){
	int check;
	check=evaluateExpression("++30");
	
	TEST_ASSERT_EQUAL(30,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_negative_80(void){
	int check;
	check=evaluateExpression("+-80");
	
	TEST_ASSERT_EQUAL(-80,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_positive_70(void){
	int check;
	check=evaluateExpression("-+70");
	
	TEST_ASSERT_EQUAL(-70,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_positive_positive_45(void){
	int check;
	check=evaluateExpression("+++45");
	
	TEST_ASSERT_EQUAL(45,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_negative_negative_negative_66(void){
	int check;
	check=evaluateExpression("----66");
	
	TEST_ASSERT_EQUAL(66,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_positive_negative_15(void){
	int check;
	check=evaluateExpression("-+-15");
	
	TEST_ASSERT_EQUAL(15,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_positive_positive_21(void){
	int check;
	check=evaluateExpression("-+-21");
	
	TEST_ASSERT_EQUAL(21,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_positive_negative_25(void){
	int check;
	check=evaluateExpression("++-25");
	
	TEST_ASSERT_EQUAL(-25,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_negative_negative_31(void){	
	int check;
	check=evaluateExpression("+--31");
	
	TEST_ASSERT_EQUAL(31,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_positive_negative_negative_14(void){	
	int check;
	check=evaluateExpression("++--14");
	
	TEST_ASSERT_EQUAL(14,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_negative_positive_positive_18(void){	
	int check;
	check=evaluateExpression("--++18");
	
	TEST_ASSERT_EQUAL(18,check);
	printf("Answer : %d \n",check);
}

void test_should_longer_prefix_expression(void){	
	int check;
	check=evaluateExpression("-+-++++---+-+-99");
	TEST_ASSERT_EQUAL(-99,check);
	printf("Answer : %d \n",check);
}

void test_should_throw_error_illegal_argument_for_2_plus(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("2+");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_should_throw_error_illegal_argument_for_multiply_2(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("*2");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX,e);
	}
}

void test_should_throw_error_illegal_argument_for_left_bracket_2(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("(2");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_should_throw_error_cannot_convert_to_prefix_for_negative_multiply_10(void){
	int check;
	CEXCEPTION_T e;
	
	Try{
		check=evaluateExpression("-*10");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX,e);
	}
}

void test_should_throw_error_cannot_convert_to_prefix_for_multiply(void){
	int check;
	CEXCEPTION_T e;
	
	Try{
		check=evaluateExpression("*");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX,e);
	}
}

void test_should_throw_error_expecting_number_for__evaluate_multiply(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("-");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_EXPECTING_NUMBER,e);
	}
}
*/
/******************************************************************************************
	Tests for evaluatePrefixesAndNumber(char *expression,token,numberStack,operatorStack)
*******************************************************************************************/
/*
void test_evaluate_should_push_10_into_number_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("10");
	String *tokenizer = stringNew(newText);
	
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("10",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(10,((Number*)token)->value);
}

void test_evaluate_should_push_negative_into_operatorStack_and_10_into_number_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-5");
	String *tokenizer = stringNew(newText);
	//-
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-5",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("-",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(MINUS_OP,((Operator*)token)->info->id);
	//5
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-5",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(5,((Number*)token)->value);
}

void test_evaluate_should_push_negative_and_plus_into_operatorStack_and_6_into_number_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-+6");
	String *tokenizer = stringNew(newText);
	
	//-
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+6",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("-",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(MINUS_OP,((Operator*)token)->info->id);
	//+
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+6",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(PLUS_OP,((Operator*)token)->info->id);
	//5
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+6",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(6,((Number*)token)->value);
}

void test_evaluate_should_push_negative_plus_negative_into_operatorStack_and_9_into_number_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-+-9");
	String *tokenizer = stringNew(newText);
	
	//-
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+-9",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("-",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(MINUS_OP,((Operator*)token)->info->id);
	//+
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+-9",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(PLUS_OP,((Operator*)token)->info->id);
	//-
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+-9",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("-",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(MINUS_OP,((Operator*)token)->info->id);
	//9
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("-+-9",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(9,((Number*)token)->value);
}

void test_evaluate_opening_bracket_7(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("(7");
	String *tokenizer = stringNew(newText);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(7",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//7
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(7",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(7,((Number*)token)->value);
}

void test_evaluate_opening_opening_bracket_8(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("((8");
	String *tokenizer = stringNew(newText);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//8
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(8,((Number*)token)->value);
}

void test_evaluate_opening_opening_opening_bracket_10(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("(((8");
	String *tokenizer = stringNew(newText);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//(
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);
	
	//8
	token=getToken(tokenizer);
	evaluatePrefixesAndNumber("(((8",token,numberStack,operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(8,((Number*)token)->value);
}

void test_evaluate_multiply_should_throw_error_cannot_convert_to_prefix_operator(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("*");
	String *tokenizer = stringNew(newText);
	
	//(
	token=getToken(tokenizer);
	Try
	{
		evaluatePrefixesAndNumber("*",token,numberStack,operatorStack);
		TEST_FAIL_MESSAGE("Should throw Error no expression ");
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX ,e);
	}
}

void test_evaluate_negative_multiply_should_throw_error_cannot_convert_to_prefix_operator(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-*");
	String *tokenizer = stringNew(newText);
	
	//-*
	token=getToken(tokenizer);
	token=getToken(tokenizer);
	Try
	{
		evaluatePrefixesAndNumber("-*",token,numberStack,operatorStack);
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX,e);
	}
}

void test_evaluate_negative_should_throw_error_expecting_number(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-");
	String *tokenizer = stringNew(newText);
	token=getToken(tokenizer);
	token=getToken(tokenizer);
	
	Try
	{
		evaluatePrefixesAndNumber("-",token,numberStack,operatorStack);
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_EXPECTING_NUMBER,e);
	}
}

void test_evaluate_negative_positive_should_throw_error_expecting_number(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("-+");
	String *tokenizer = stringNew(newText);
	token=getToken(tokenizer);
	token=getToken(tokenizer);
	token=getToken(tokenizer);
	Try
	{
		evaluatePrefixesAndNumber("-+",token,numberStack,operatorStack);
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_EXPECTING_NUMBER,e);
	}
}

void test_evaluate_divide_multiply_should_throw_error_expecting_number(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew("/*");
	String *tokenizer = stringNew(newText);
	token=getToken(tokenizer);
	token=getToken(tokenizer);
	Try
	{
		evaluatePrefixesAndNumber("/*",token,numberStack,operatorStack);
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_CANNOT_CONVERT_TO_PREFIX,e);
	}
}
*/
/*****************************************************************************************
	Tests for evaluatePostfixesAndInfix(char *expression,(token,numberStack,operatorStack)
*******************************************************************************************/
/*
void test_should_throw_error_expecting_operator(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	//2+
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Number number4 = {.type= NUMBER_TOKEN, .value=4};
	
	stackPush(&number2,numberStack);
	
	Try{
		evaluatePostfixesAndInfix("2 4",(Token*)&number4,numberStack,operatorStack);
	}Catch(e){
		TEST_ASSERT_EQUAL(ERR_EXPECTING_OPERATOR,e);
	}
}	

void test_should_evaluate_2_plus_and_push_to_their_respective_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	//2+
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	Operator plus =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	stackPush(&number2,numberStack);
	
	evaluatePostfixesAndInfix("2+",(Token*)&plus,numberStack,operatorStack);
	token = (Token*)stackPop(numberStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(2,((Number*)token)->value);
	
	token = (Token*)stackPop(operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)token)->info->id);
}	

void test_should_evaluate_opening_bracket_14_closing_bracket_plus_and_push_to_their_respective_stack(void){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	
	Operator openBracket =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	Operator closeBracket =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	Operator plus =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	stackPush(&openBracket,operatorStack);
	stackPush(&number10,numberStack);
	
	evaluatePostfixesAndInfix("(10)+",(Token*)&openBracket,numberStack,operatorStack);
	token = (Token*)stackPop(operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("(",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(OPENING_BRACKET_OP,((Operator*)token)->info->id);

	token = (Token*)stackPop(numberStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL(10,((Number*)token)->value);
	
	evaluatePostfixesAndInfix("(10)+",(Token*)&closeBracket,numberStack,operatorStack);
	token = (Token*)stackPop(operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING(")",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(CLOSING_BRACKET_OP,((Operator*)token)->info->id);
	
	evaluatePostfixesAndInfix("(10)+",(Token*)&plus,numberStack,operatorStack);
	token = (Token*)stackPop(operatorStack);
	TEST_ASSERT_NOT_NULL(token);
	TEST_ASSERT_EQUAL_STRING("+",((Operator*)token)->info->symbol);
	TEST_ASSERT_EQUAL(ADD_OP,((Operator*)token)->info->id);
}	

void test_should_evaluate_12_closing_bracket_plus_and_push_to_their_respective_stack(void){
	CEXCEPTION_T e;
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Operator openBracket =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number10 = {.type= NUMBER_TOKEN, .value=10};
	Operator closeBracket =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(CLOSING_BRACKET_OP)};
	Operator plus =  {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	
	stackPush(&openBracket,operatorStack);
	stackPush(&number10,numberStack);
	
	Try
	{
		evaluatePostfixesAndInfix("10)",(Token*)&closeBracket,numberStack,operatorStack);
	}
	Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_EXPECTING_NUMBER,e);
	}
}	
*/



/*
void test_should_evaluate_negative_1_plus_10(void){
	int check;
	check=evaluateExpression("-1+10");
	TEST_ASSERT_EQUAL(9,check); 
	printf("Answer : %d \n",check);
}

void test_should_evaluate_testing(void){
	int check;
	check=evaluateExpression("10*-5");
	TEST_ASSERT_EQUAL(-50,check); 
	printf("Answer : %d \n",check);
}

void test_should_throw_error_illegal_argument_for_2_multiply_divide(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("2/*");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERATOR,e);
	}
}

void test_should_throw_error_illegal_argument_for_right_bracket_5(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("5)");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERATOR,e);
	}
}










void test_should_evaluate_1_plus_10_minus_5(void){
	int check;
	check=evaluateExpression("1+10-5");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_1_multiply_10_divide_5(void){
	int check;
	check=evaluateExpression("1*10/5");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_1_plus_negative_10_minus_5(void){
	int check;
	check=evaluateExpression("-1+-10-5");
	TEST_ASSERT_EQUAL(-16,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_100_divide_4_multiply_5(void){
	int check;
	check=evaluateExpression("100/4*5");
	TEST_ASSERT_EQUAL(125,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_100_divide_4_multiply_5(void){
	int check;
	check=evaluateExpression("-100/4*5");
	TEST_ASSERT_EQUAL(-125,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_10_multiply_negative_5(void){
	int check;
	check=evaluateExpression("-5*10");
	TEST_ASSERT_EQUAL(-50,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_20_multiply_2(void){
	int check;
	check=evaluateExpression("20*2");
	TEST_ASSERT_EQUAL(40,check);
	printf("Answer : %d \n",check);
}
	
void test_should_evaluate_two_plus_three_multiply_four(void){
	int check;
	check=evaluateExpression("2+3*4");
	TEST_ASSERT_EQUAL(14,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_two_multiply_three_plus_four(void){
	int check;
	check=evaluateExpression("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_2_plus_negative_3(void){
	int check;
	check=evaluateExpression("2+-3");
	TEST_ASSERT_EQUAL(-1,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_opening_bracket_2_closing_bracket(void){
	int check;
	check=evaluateExpression("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_opening_bracket_2_plus_3_closing_bracket(void){
	int check;
	check=evaluateExpression("(2+3)");
	TEST_ASSERT_EQUAL(5,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_opening_bracket_opening_bracket_2_plus_3_closing_bracket_closing_bracket(void){
	int check;
	check=evaluateExpression("((10+3))");
	TEST_ASSERT_EQUAL(13,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_opening_bracket_opening_bracket_2_plus_3_closing_bracket_closing_bracket_multiply_5(void){
	int check;
	check=evaluateExpression("((10+3))*5");
	TEST_ASSERT_EQUAL(65,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_open_open_bracket_2_plus_3_multiply_4_closing_closing_bracket(void){
	int check;
	check=evaluateExpression("((2+3*4))");
	TEST_ASSERT_EQUAL(14,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_open_open_bracket_2_multiply_3_plus_4_closing_closing_bracket(void){
	int check;
	check=evaluateExpression("((2*3+4))");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d \n",check);

}

void test_should_evaluate_50_plus_open_open_bracket_2_multiply_3_plus_4_closing_closing_bracket(void){
	int check;
	check=evaluateExpression("50+((2*3+4))");
	TEST_ASSERT_EQUAL(60,check);
	printf("Answer : %d \n",check);
}
*/


