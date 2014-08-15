#include "unity.h"
#include "Evaluate.h"
#include "Token.h"
#include "LinkedList.h"
#include "Stack.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "Text.h"
#include "createNumberToken.h"
#include "StringObject.h"
#include "getToken.h"
#include "mock_tryEvaluatethenPush.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CException.h"

void setUp(void){}
void tearDown(void){}

/***********************************************************************	
 Test on function operatorEvaluate
 Input parameter : 
					1)Stack *numberStack
					2)Operator *opeToken

 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								
 ***********************************************************************/	
 
 void test_operatorEvaluate_should_throw_error_when_encounter_invalid_operator(void){
	
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	Token *tempToken;
	Number *tempAns;
	ErrorCode exception;
	
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"1#2"};
	Number number1 = {.type= NUMBER_TOKEN, .value=1};
	Operator hashTag = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(HASH_OP)};
	Number number2 = {.type= NUMBER_TOKEN, .value=2};
	
	Try{
		 operatorInfixEvaluate(numberStack,&hashTag);
		TEST_FAIL_MESSAGE("Invalid Operator should throw Error Not Operator");
	}
	Catch(exception){
		TEST_ASSERT_EQUAL(ERR_INVALID_OPERATOR,exception);
	}
}	

void test_operatorEvaluate_100_MINUS_37(void)
{
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"100-37"};
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number37 = {.type= NUMBER_TOKEN, .value=37};
	Number number63;
	
	stackPush(&number100,numberStack);
	stackPush(&minus,operatorStack);
	stackPush(&number37,numberStack);
	
	
	operatorInfixEvaluate(numberStack,&minus);
}

void test_operatorEvaluate_56_BITWISEXOR_30(void)
{
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"56^30"};
	Number number56 = {.type= NUMBER_TOKEN, .value=56};
	Operator bitwiseXOR = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(BITWISE_XOR_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Number number38;
	
	stackPush(&number56,numberStack);
	stackPush(&bitwiseXOR,operatorStack);
	stackPush(&number30,numberStack);
	
	operatorEvaluate(numberStack,&bitwiseXOR);
	
}

void test_operatorEvaluate_opening_bracket_3_should_throw_error(void){
	Token *tempToken;
	Number *tempAns;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	int check;
	//Initialize tokenizer,token and stack
	
	Operator openBracket = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(OPENING_BRACKET_OP)};
	Number number3 = {.type= NUMBER_TOKEN, .value=3};
	
	stackPush(&openBracket,operatorStack);
	stackPush(&number3,numberStack);
	stackPush(NULL,operatorStack);
	
	operatorEvaluate(numberStack,&openBracket);
}
/***********************************************************************	
 Test on function evaluateAllOperatorOnStack
 Input parameter : 
					1)Stack *numberStack
					2)Stack *operatorStack
					
 Using following mock function : 
								1)stringCreate()
								2)getToken()
								3)stackPop()  
								4)stackPush()
								5)createNumberToken()
								6)operatorEvaluate
								
 ***********************************************************************/	

 void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20(void){
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"100/5*6+99-20"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide= {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Number number120 = {.type= NUMBER_TOKEN, .value=120};
	Number number219 = {.type= NUMBER_TOKEN, .value=219};
	Number number199 = {.type= NUMBER_TOKEN, .value=199};
	
	stackPush(&number100,numberStack);
	stackPush(&divide,operatorStack);
	stackPush(&number5,numberStack);
	stackPush(&multiply,operatorStack);
	stackPush(&number6,numberStack);
	stackPush(&plus,operatorStack);
	stackPush(&number99,numberStack);
	stackPush(&minus,operatorStack);
	stackPush(&number20,numberStack);
	
	evaluateAllOperatorOnStack(numberStack,operatorStack);
}

void test_evaluateAllOperatorOnStack_100_divide_5_multiply_6_plus_99_minus_20_modulus_30(void){
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	Token *tempToken;
	Number *tempAns;
	int check;
	//Initialize tokenizer,token and stack
	String tokenizer = {.text = t"100/5*6+99-20%30"};
	
	Number number100 = {.type= NUMBER_TOKEN, .value=100};
	Operator divide= {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(DIV_OP)};
	Number number5 = {.type= NUMBER_TOKEN, .value=5};
	Operator multiply = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MUL_OP)};
	Number number6 = {.type= NUMBER_TOKEN, .value=6};
	Operator plus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(ADD_OP)};
	Number number99 = {.type= NUMBER_TOKEN, .value=99};
	Operator minus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(SUB_OP)};
	Number number20 = {.type= NUMBER_TOKEN, .value=20};
	Operator modulus = {.type= OPERATOR_TOKEN, .info=operatorFindInfoByID(MOD_OP)};
	Number number30 = {.type= NUMBER_TOKEN, .value=30};
	Number number120 = {.type= NUMBER_TOKEN, .value=120};
	Number number219 = {.type= NUMBER_TOKEN, .value=219};
	Number number199 = {.type= NUMBER_TOKEN, .value=199};
	Number number19 = {.type= NUMBER_TOKEN, .value=19};;
	
	stackPush(&number100,numberStack);
	stackPush(&divide,operatorStack);
	stackPush(&number5,numberStack);
	stackPush(&multiply,operatorStack);
	stackPush(&number6,numberStack);
	stackPush(&plus,operatorStack);
	stackPush(&number99,numberStack);
	stackPush(&minus,operatorStack);
	stackPush(&number20,numberStack);
	stackPush(&modulus,operatorStack);
	stackPush(&number30,numberStack);

	evaluateAllOperatorOnStack(numberStack,operatorStack);
}




















