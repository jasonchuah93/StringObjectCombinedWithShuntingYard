#include "unity.h"
#include "Evaluate.h"
#include "mock_Stack.h"
#include "LinkedList.h"
#include "Token.h"
#include "mock_StringObject.h"
#include "mock_getToken.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "mock_createNumberToken.h"
#include "mock_Text.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/***********************************************************************	
 Test on tryEvaluateOperatorOnStackThenPush
 Input parameter : 
					1)Operator *newToken
					2)Stack *numberStack
					3)Stack *operatorStack

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)operatorEvaluate
								
 ***********************************************************************/	

 void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorToken_if_Operator_Stack_is_empty(void){
	Stack numberStack;
	Stack operatorStack;
	Operator *opeToken;
	
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(opeToken,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(opeToken,&numberStack,&operatorStack);
}
 
void test_tryEvaluateOperatorOnStackThenPush_will_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_higher_than_previousToken(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	
	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPush_Expect(&plus,&operatorStack);
	stackPush_Expect(&multiply,&operatorStack);
	tryEvaluateOperatorOnStackThenPush(&multiply,&numberStack,&operatorStack);
}
 
void test_tryConvertToPrefixThenPush_Will_Convert_Infix_Token_To_Prefix_Token_In_The_Alternative_Table(void){
	Stack operatorStack;
	Operator plus = {.type=OPERATOR_TOKEN , .info=operatorFindInfoByID(ADD_OP)};
	
	stackPush_Expect(&plus,&operatorStack);
	tryConvertToPrefixThenPush(&plus,&operatorStack);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,plus.type);
	TEST_ASSERT_EQUAL(150,plus.info->precedence);
	TEST_ASSERT_EQUAL(PLUS_OP,plus.info->id);
}

void test_tryConvertToPrefixThenPush_Will_Convert_Infix_Token_To_Prefix_Token_In_The_Alternative_Table2(void){
	Stack operatorStack;
	Operator minus = {.type=OPERATOR_TOKEN , .info=operatorFindInfoByID(SUB_OP)};
	
	stackPush_Expect(&minus,&operatorStack);
	tryConvertToPrefixThenPush(&minus,&operatorStack);
	TEST_ASSERT_EQUAL(OPERATOR_TOKEN,minus.type);
	TEST_ASSERT_EQUAL(150,minus.info->precedence);
	TEST_ASSERT_EQUAL(MINUS_OP,minus.info->id);
}

/* 
void test_tryEvaluateOperatorOnStackThenPush_will_not_push_OperatorTOken_into_Operator_Stack_if_newToken_precendence_is_lower_than_previousToken(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	//1*2+3
	Number number1 = {.type= NUMBER, .value=1};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};
	Number number2 = {.type= NUMBER, .value=2};
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number3 = {.type= NUMBER, .value=3};
	Number tempAns = {.type= NUMBER, .value=2};
	Token *tempAnsToken =(Token*)&tempAns;
	
	stackPop_ExpectAndReturn(&operatorStack,&multiply);
	stackPop_ExpectAndReturn(&numberStack,&number2);
	stackPop_ExpectAndReturn(&numberStack,&number1);
	createNumberToken_ExpectAndReturn(2,tempAnsToken);
	stackPush_Expect(&tempAns,&numberStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&plus,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&plus,&numberStack,&operatorStack);
}
 
 void test_tryEvaluateOperatorOnStackThenPush_evaluate_newToke_and_previousToken_if_both_have_same_precedence(void)
{
	Stack numberStack;
	Stack operatorStack;
	
	//100-20-16
	Number number100 = {.type= NUMBER, .value=100};
	Operator minus = {.type= OPERATOR, .id=SUBTRACT, .precedence=70};
	Number number20 = {.type= NUMBER, .value=20};
	Operator minusA = {.type= OPERATOR, .id=SUBTRACT , .precedence=70};
	Number number16 = {.type= NUMBER, .value=16};
	Number tempAns = {.type= NUMBER, .value=80};
	Token *tempAnsToken =(Token*)&tempAns;
	
	stackPop_ExpectAndReturn(&operatorStack,&minus);
	stackPop_ExpectAndReturn(&numberStack,&number20);
	stackPop_ExpectAndReturn(&numberStack,&number100);
	createNumberToken_ExpectAndReturn(80,tempAnsToken);
	stackPush_Expect(&tempAns,&numberStack);
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&minusA,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&minusA,&numberStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_1(void)
{
	Stack numberStack;
	Stack operatorStack;
	//21*22+30/6
	Number number21 = {.type= NUMBER, .value=21};
	Operator multiply = {.type= OPERATOR, .id=MULTIPLY, .precedence=100};
	Number number22 = {.type= NUMBER, .value=22};
	
	Number tempAns = {.type= NUMBER, .value=462};
	Token *tempAnsToken =(Token*)&tempAns;
	
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number30 = {.type= NUMBER, .value=30};
	Operator divide = {.type= OPERATOR, .id=DIVIDE, .precedence=100};
	Number number6 = {.type= NUMBER, .value=6};
	
		
	stackPop_ExpectAndReturn(&operatorStack,&multiply);
	stackPop_ExpectAndReturn(&numberStack,&number22);
	stackPop_ExpectAndReturn(&numberStack,&number21);
	createNumberToken_ExpectAndReturn(462,tempAnsToken);
	stackPush_Expect(tempAnsToken,&numberStack);

	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPush_Expect(&plus,&operatorStack);
	stackPush_Expect(&divide,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&divide,&numberStack,&operatorStack);
}

void test_tryEvaluateOperatorOnStackThenPush_evaluate_all_operatorTokens_to_be_push_in_the_operator_stack_2(void)
{
	Stack dataStack;
	Stack operatorStack;
	//21+22&30|6
	Number number21 = {.type= NUMBER, .value=21};
	Operator plus = {.type= OPERATOR, .id=ADD, .precedence=70};
	Number number22 = {.type= NUMBER, .value=22};
	
	Number tempAns1 = {.type= NUMBER, .value=43};
	Token *tempAnsToken1 =(Token*)&tempAns1;
	
	Operator bitwiseAND = {.type= OPERATOR, .id=BITWISE_AND, .precedence=20};
	Number number30 = {.type= NUMBER, .value=30};
	Operator bitwiseOR = {.type= OPERATOR, .id=BITWISE_OR, .precedence=10};
	Number number6 = {.type= NUMBER, .value=6};
	
	Number tempAns2 = {.type= NUMBER, .value=6};
	Token *tempAnsToken2 =(Token*)&tempAns2;
	
	stackPop_ExpectAndReturn(&operatorStack,&plus);
	stackPop_ExpectAndReturn(&dataStack,&number22);
	stackPop_ExpectAndReturn(&dataStack,&number21);
	createNumberToken_ExpectAndReturn(43,tempAnsToken1);
	stackPush_Expect(tempAnsToken1,&dataStack);

	stackPop_ExpectAndReturn(&operatorStack,&bitwiseAND);
	stackPop_ExpectAndReturn(&dataStack,&number30);
	stackPop_ExpectAndReturn(&dataStack,&number6);
	createNumberToken_ExpectAndReturn(6,tempAnsToken2);
	stackPush_Expect(tempAnsToken2,&dataStack);
	
	stackPop_ExpectAndReturn(&operatorStack,NULL);
	stackPush_Expect(&bitwiseOR,&operatorStack);
	
	tryEvaluateOperatorOnStackThenPush(&bitwiseOR,&dataStack,&operatorStack);
}
*/
 
 
 
 
 
 
 
 
 
 
 
 