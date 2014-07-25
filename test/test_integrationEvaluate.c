#include "unity.h"
#include "Evaluate.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Token.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h"
#include "stackForEvaluate.h"
#include "ErrorCode.h"
#include "CException.h"
#include "CharSet.h"
#include "Text.h"
#include "StringObject.h"
#include "Types.h"




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
/*
void test_should_return_3_for_1_plus_2(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"1+2", .start = 0, .length=3};
	
	//stringCreate_ExpectAndReturn("1+2",&tokenizer);
	
	check=evaluate("1+2");
	TEST_ASSERT_EQUAL(3,check);
	printf("Answer : %d ",check);
}
*/
/*
void test_should_return_6_for_60_divide_10(void){
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "60/10", .startIndex = 0, .length=3};
	
	stringCreate_ExpectAndReturn("60/10",&tokenizer);
	
	check=evaluate("60/10");
	TEST_ASSERT_EQUAL(6,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4(void){	
	
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4", .startIndex = 0, .length = 5};
	
	
	//Evaluate the expression
	
	stringCreate_ExpectAndReturn("2*3+4",&tokenizer);
	
	
	check=evaluate("2*3+4");
	TEST_ASSERT_EQUAL(10,check);
	printf("Answer : %d ",check);

}

void test_evaluate_2_PLUS_3_MULTIPLY_4_PLUS_5_MULTIPLY_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2+3*4+5*6", .startIndex = 0, .length = 9};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2+3*4+5*6",&tokenizer);
	
	check=evaluate("2+3*4+5*6");
	TEST_ASSERT_EQUAL(44,check);
	printf("Answer : %d ",check);
}

void test_evaluate_2_MULTIPLY_3_PLUS_4_MULTIPLY_5_PLUS_6(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "2*3+4*5+6", .startIndex = 0, .length = 9};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2*3+4*5+6",&tokenizer);
	
	check=evaluate("2*3+4*5+6");
	TEST_ASSERT_EQUAL(32,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10(void){
	
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10", .startIndex = 0, .length = 11};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10");
	TEST_ASSERT_EQUAL(7,check);
	printf("Answer : %d ",check);
}

void test_2_OR_3_PLUS_4_MULTIPLY_5_MINUS_6_MINUS_10_OR_10_AND_53_XOR_21(void){
	
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21", .startIndex = 0, .length = 17};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10|10&53^21",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10|10&53^21");
	TEST_ASSERT_EQUAL(16,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_different_expression(void){
	int check;
	String tokenizer = {.rawString = "2|3+4*5-6-10|10&53^21+95%6^200%5*80", .startIndex = 0, .length = 27};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3+4*5-6-10|10&53^21+95%6^200%5*80",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3+4*5-6-10|10&53^21+95%6^200%5*80");
	TEST_ASSERT_EQUAL(31,check);
	printf("Answer : %d ",check);
}

void test_evaluate_with_longer_expression(void){
	int check;
	String tokenizer = {.rawString = "2|3&4^5|6^10|10&53^21&95|6^200&5|80"};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("2|3&4^5|6^10|10&53^21&95|6^200&5|80",&tokenizer);
	
	//Token number 2
	check=evaluate("2|3&4^5|6^10|10&53^21&95|6^200&5|80");
	TEST_ASSERT_EQUAL(84,check);
	printf("Answer : %d ",check);
}

void test_should_evaluate_left_parenthesis_2_right_parenthesis(void){
	
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(2)"};
	
	stringCreate_ExpectAndReturn("(2)",&tokenizer);
	
	
	check=evaluate("(2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
	
}	
	
void test_should_evaluate_left_parenthesis_100_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(100)"};
	
	stringCreate_ExpectAndReturn("(100)",&tokenizer);
	
	check=evaluate("(100)");
	TEST_ASSERT_EQUAL(100,check);
	printf("Answer : %d ",check);
	
}

void test_should_evaluate_left_parenthesis_100_plus_100_divide_20_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(100-60/20)"};
	
	stringCreate_ExpectAndReturn("(100-60/20)",&tokenizer);
	
	check=evaluate("(100-60/20)");
	TEST_ASSERT_EQUAL(97,check);
	printf("Answer : %d ",check);
	
}

void test_should_evaluate_left_left_parenthesis_22_right_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "((22))"};
	
	stringCreate_ExpectAndReturn("((22))",&tokenizer);
	
	check=evaluate("((22))");
	TEST_ASSERT_EQUAL(22,check);
	printf("Answer : %d ",check);
	
}	
	
void test_should_evaluate_left_left_left_parenthesis_55_right_right_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(((55)))", .startIndex = 0, .length = 6};
	
	stringCreate_ExpectAndReturn("(((55)))",&tokenizer);
	
	check=evaluate("(((55)))");
	TEST_ASSERT_EQUAL(55,check);
	printf("Answer : %d ",check);
	
}	

void test_should_evaluate_10_multiply_left_parenthesis_6_plus_2_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "10*(6+2)", };
	
	stringCreate_ExpectAndReturn("10*(6+2)",&tokenizer);
	
	check=evaluate("10*(6+2)");
	TEST_ASSERT_EQUAL(80,check);
	printf("Answer : %d ",check);
	
}	

void test_should_evaluate_left_parenthesis_10_divide_5_right_parenthesis_multiply_left_parenthesis_6_plus_2_right_parenthesis(void){
	int check;
	int e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(10/5)*(6+2)", };
	
	stringCreate_ExpectAndReturn("(10/5)*(6+2)",&tokenizer);
	
	check=evaluate("(10/5)*(6+2)");
	TEST_ASSERT_EQUAL(16,check);
	printf("Answer : %d ",check);
	
}	

void test_left_left_left_bracket_20_plus_60_divide_4_right_right_right_bracket(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(((20+60/4)))"};
	
	stringCreate_ExpectAndReturn("(((20+60/4)))",&tokenizer);
	
	check=evaluate("(((20+60/4)))");
	TEST_ASSERT_EQUAL(35,check);
	printf("Answer : %d ",check);
}

void test_left_bracket_6_plus_97_right_bracket_multiply_30(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "(6+97)*30"};
	
	stringCreate_ExpectAndReturn("(6+97)*30",&tokenizer);
	
	check=evaluate("(6+97)*30");
	TEST_ASSERT_EQUAL(3090,check);
	printf("Answer : %d ",check);
}

void test_one_minus_hundred(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "1-100"};
	
	stringCreate_ExpectAndReturn("1-100",&tokenizer);
	
	check=evaluate("1-100");
	TEST_ASSERT_EQUAL(-99,check);
	printf("Answer : %d ",check);
}

void test_evaluate_positive_fifty(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "+50"};
	
	stringCreate_ExpectAndReturn("+50",&tokenizer);
	
	check=evaluate("+50");
	TEST_ASSERT_EQUAL(50,check);
	printf("Answer : %d ",check);
}

void test_evaluate_negative_hundred(void){
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "-100"};
	
	stringCreate_ExpectAndReturn("-100",&tokenizer);
	
	check=evaluate("-100");
	TEST_ASSERT_EQUAL(-100,check);
	printf("Answer : %d ",check);
}

void test_evaluate_multiply_ten_should_return_error(void){
	int check,e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "*10"};
	
	stringCreate_ExpectAndReturn("*10",&tokenizer);
	
	Try{
		evaluate("*10");
	}Catch(e){
		TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,e);
		return;
	}
	
}

void test_evaluate_80_multiply_should_return_error(void){
	int check,e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "80*"};
	
	stringCreate_ExpectAndReturn("80*",&tokenizer);
	
	Try{
		evaluate("80*");
	}Catch(e){
		TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,e);
		return;
	}
	
}

void test_evaluate_50_add_should_return_error(void){
	int check,e;
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "50+"};
	
	stringCreate_ExpectAndReturn("50+",&tokenizer);
	
	Try{
		evaluate("50+");
	}Catch(e){
		TEST_ASSERT_EQUAL(UNKNOWN_OPERATOR,e);
		return;
	}
	
}

void test_NEGATIVE_2_NEGATIVE_3_SHOULD_RETURN_NEGATIVE_6(void){
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.rawString = "-2*3", .startIndex = 0, .length = 4 };
	
	stringCreate_ExpectAndReturn("-2*3",&tokenizer);
	
	check=evaluate("-2*3");
	TEST_ASSERT_EQUAL(-6,check);
	printf("Answer : %d ",check);

}

void test_LEFT_PARENTHESIS_10_MULTIPLY_100_RIGHT_PARENTHESIS_DIVIDE_BY_LEFT_PARENTHESIS_LEFT_PARENTHESIS_NEGATIVE_5_MULTIPLY_6_RIGHT_PARENTHESIS_SUBTRACT_LEFT_PARENTHESIS_2_MINUS_30_RIGHT_PARENTHESIS_RIGHT_PARENTHESIS(void) {
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "(10*100)/((5*6)-(2-30))", .startIndex = 0, .length = 24 };
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("(10*100)/((5*6)-(2-30))",&tokenizer);
	
	check=evaluate("(10*100)/((5*6)-(2-30))");
	TEST_ASSERT_EQUAL(17,check);
	printf("Answer : %d ",check);
	
	
	
}

void test_NEGATIVE_LEFT_PARENTHESIS_NEGATIVE_2_RIGHT_PARENTHESIS(void){
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "-(-2)", .startIndex = 0, .length = 5 };
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-(-2)",&tokenizer);
	
	check=evaluate("-(-2)");
	TEST_ASSERT_EQUAL(2,check);
	printf("Answer : %d ",check);
}

void test_NEGATIVE_LEFT_PARENTHESIS_POSITIVE_LEFT_PARENTHESIS_NEGATIVE_LEFT_PARENTHESIS__NEGATIVE_1_RIGHT_PARENTHESIS_MULTIPLY_3_RIGHT_PARENTHESIS_SUBTRACT_FOUR_RIGHT_PARENTHESIS(void){
	
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "-(+(-(-1)*3)-4)", .startIndex = 0, .length = 15 };
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-(+(-(-1)*3)-4)",&tokenizer);
	
	check=evaluate("-(+(-(-1)*3)-4)");
	TEST_ASSERT_EQUAL(1,check);
	printf("Answer : %d ",check);
}

void test_negative_space_two(void){
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "-     14"};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("-     14",&tokenizer);
	
	check=evaluate("-     14");
	TEST_ASSERT_EQUAL(-14,check);
	printf("Answer : %d ",check);
}

void test_LOGIC_NOT_twelve(void){
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "!12"};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("!12",&tokenizer);
	
	check=evaluate("!12");
	TEST_ASSERT_EQUAL(0,check);
	printf("Answer : %d ",check);
}

void xtest_LOGIC_NOT_LOGIC_NOT_twelve(void){
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "!!12"};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("!!12",&tokenizer);
	
	check=evaluate("!!12");
	TEST_ASSERT_EQUAL(1,check);
	printf("Answer : %d ",check);
}

void xtest_minus_minus_five(void){
	Stack numStack;
	Stack opeStack;
	int check;
	
	String tokenizer = {.rawString = "--5"};
	
	//Evaluate the expression
	stringCreate_ExpectAndReturn("--5",&tokenizer);
	
	check=evaluate("--5");
	TEST_ASSERT_EQUAL(5,check);
	printf("Answer : %d ",check);
}

*/