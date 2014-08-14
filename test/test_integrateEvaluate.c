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
/*
void test_should_throw_error_illegal_argument_for_two_plus(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("2+");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_should_throw_error_illegal_argument_for_multiply_two(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("*2");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_should_throw_error_illegal_argument_for_multiply(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("*");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
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

void test_should_throw_error_illegal_argument_for_right_bracket_5(void){
	int check;
	CEXCEPTION_T e;
	Try{
		check=evaluateExpression("5)");
	}Catch(e)
	{
		TEST_ASSERT_EQUAL(ERR_ILLEGAL_ARGUMENT,e);
	}
}

void test_should_evaluate_two_plus_three_multiply_four(void){
	int check;
	check=evaluateExpression("2+3*4");
	
	TEST_ASSERT_EQUAL(14,check);
}

void test_should_evaluate_one_plus_two(void)
{
	int check;
	check=evaluateExpression("1+2");
	
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_two_multiply_three_plus_four(void){
	int check;
	check=evaluateExpression("2*3+4");
	
	TEST_ASSERT_EQUAL(10,check);
}
void test_should_evaluate_BITWISE_NOT_5(void){
	int check;
	check=evaluateExpression("~5");
	
	TEST_ASSERT_EQUAL(-6,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_LOGICAL_NOT_10(void){
	int check;
	check=evaluateExpression("!10");
	
	TEST_ASSERT_EQUAL(0,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_negative_two(void){
	int check;
	check=evaluateExpression("--2");
	
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_twenty(void){
	int check;
	check=evaluateExpression("-20");
	
	TEST_ASSERT_EQUAL(-20,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_hundred(void){
	int check;
	check=evaluateExpression("+100");
	
	TEST_ASSERT_EQUAL(100,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_positive_thirty(void){
	int check;
	check=evaluateExpression("++30");
	
	TEST_ASSERT_EQUAL(30,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_positive_negative_eigthy(void){
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

void test_should_evaluate_negative_negative_negative_60(void){
	int check;
	check=evaluateExpression("---60");
	
	TEST_ASSERT_EQUAL(-60,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_negative_negative_negative_66(void){
	int check;
	check=evaluateExpression("----66");
	
	TEST_ASSERT_EQUAL(66,check);
	printf("Answer : %d \n",check);
}

void test_should_evaluate_negative_positive_negative_fifteen(void){
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
*/
void test_should_evaluate_10_minus_4_minus_3(void){	
	int check;
	check=evaluateExpression("10-4-3");
	
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d \n",check);
}

