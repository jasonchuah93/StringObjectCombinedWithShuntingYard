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
 Test on function evaluate
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

								
Mock function left stringCreate 


********************************************************************************************************************************/	

void test_should_return_3_for_1_plus_2(void){
	int check;
	//Initialize tokenizer,token and stack
	
	check=evaluatex("3");
	TEST_ASSERT_EQUAL(3,check);
	
}

/*
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

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	
	int check;
	check=evaluate("2|3+4*5-6-10");
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
*/

void test_evaluate_two_plus_three(void){
	
}
