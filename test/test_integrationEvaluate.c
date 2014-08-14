#include "unity.h"
#include "Evaluate.h"
#include "Stack.h"
#include "LinkedList.h"
#include "StringObject.h"
#include "getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h"
#include "stackForEvaluate.h"
#include "Text.h"
#include "Types.h"
#include "Token.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CException.h"


void setUp(void){}
void tearDown(void){}

/*********************************************************************************************************************************
 Test on function evaluate(char *expression)
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

After doing the mocking tests at test_Evaluate.c , I running the integration test for function evaluate(char *expression)
by copying the mock test from test_Evaluate.
However, this is evaluate(char *expression) is a prototype function so this function could not evaluate
expression example like (((((25))))) and -+---++++20. 
I will improve this function and named it as evaluateExpression(char *expression). 
The TDD for evaluateExpression(char *expression) will be on file test_integrateEvaluate.c 
********************************************************************************************************************************/	

void test_evaluate_should_throw_error_if_the_expression_is_null(){
	
	ErrorCode e;
	int check;
	
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
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d ",check);
}

void test_should_return_6_for_60_divide_10(void){
	int check;
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	int check;
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_evaluate_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	int check;
	check=evaluate("3+4*5-6-10");
	TEST_ASSERT_EQUAL(7,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21(void){
	int check;
	check=evaluate("2|3+4*5-6-10|10&53^21");
	TEST_ASSERT_EQUAL(23,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_different_expression(void){
	int check;
	check=evaluate("2|3+4*5-6-10|10&53^21+95%6^200%5*80");
	TEST_ASSERT_EQUAL(31,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_longer_expression(void){
	int check;
	check=evaluate("2|3&4^5|6^10|10&53^21&95|6^200&5|80");
	TEST_ASSERT_EQUAL(95,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_43_HASHTAG_42_and_throw_error_invalid_operator(void){

	int check;
	ErrorCode e;
	Try{
		evaluate("43#42");
	}Catch(e){
		 TEST_ASSERT_EQUAL(ERR_UNKNOWN_INFIX_OPERATOR,e);
		 
	}
}

void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){
	int check;
	check=evaluate("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_left_parenthesis_25_right_parenthesis(void){
	int check;
	check=evaluate("(25)");
	TEST_ASSERT_EQUAL(25,check);
	printf("Answer : %d ",check);
}

void test_left_bracket_2_plus_3_right_bracket(void){
	int check;
	check=evaluate("(20*3-50)");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);
}


void test_logic_not_12_SHOULD_RETURN_0(void){
	int check;
	check=evaluate("!12");
	TEST_ASSERT_EQUAL(0,check);
	printf("Answer : %d ",check);

}

