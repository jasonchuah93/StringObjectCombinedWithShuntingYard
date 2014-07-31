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
	
	ErrorCode e;
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
	ErrorCode e;
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
