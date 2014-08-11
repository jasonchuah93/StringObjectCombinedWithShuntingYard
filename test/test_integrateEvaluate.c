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

void test_should_evaluate_one_plus_two(void)
{
	int check;
	check=evaluateExpression("1+2");
	
	TEST_ASSERT_EQUAL(3,check);
}

void test_should_evaluate_two_plus_three_multiply_four(void){
	int check;
	check=evaluateExpression("2+3*4");
	
	TEST_ASSERT_EQUAL(14,check);
}

void test_should_evaluate_two_multiply_three_plus_four(void){
	int check;
	check=evaluateExpression("2*3+4");
	
	TEST_ASSERT_EQUAL(10,check);
}

