#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Token.h"
#include "Text.h"
#include "CharSet.h"
#include "StringObject.h"
#include "getToken.h"
#include "Evaluate.h"
#include "CustomTypeAssert.h"
#include "Stack.h"
#include "LinkedList.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h"
#include "stackForEvaluate.h"
#include "ErrorCode.h"
#include "CException.h"

/*******************************************************************************************
 *	This function is to evaluate the expression which contains numbers and operators and
 *	return the results in number form.
 *	This function is a prototype function which use as reference to
 *	improve in the evaluateExpression(char*expression) function.
 *	Thus, this function could not evaluate expression like -2,*2,(((2))), +-+-2... *
 *	input  : expression
 *	output : none
 *	return : ((Number*)token)->value
 *
********************************************************************************************/
int evaluate(char *expression){
	Token *token;
	Number *result;

	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	if(expression ==NULL){
		Throw(ERR_NO_ARGUMENT);
	}
	Text *newText=textNew(expression);
	String *tokenizer = stringNew(newText);
	while((token=getToken(tokenizer))!=NULL ){
		if(isNumber(token)){
			stackPush(token,numberStack);
		} else if(isOperator(token)) {
			if(((Operator*)token)->info->id==OPENING_BRACKET_OP || ((Operator*)token)->info->id==CLOSING_BRACKET_OP) {
				tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			} else{
				tryEvaluateOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}
		}
	}
	if(operatorStack == NULL){
		operatorPrefixEvaluate(numberStack ,(Operator*)token);
	}else{
		evaluateAllOperatorOnStack(numberStack,operatorStack);
	}
	result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	if(operatorStack !=NULL){
		destroyStack(operatorStack);
	}

	return result->value;

}

/*******************************************************************************************
 *	This function is to evaluate prefixes and number.
 *	This function will stop and return after number is detected.
 *	input  : expression,token,numberStack,operatorStack
 *	output : none
 *	return : function
 *	Throw : ERR_EXPECTING_NUMBER
********************************************************************************************/

void evaluatePrefixesAndNumber(char *expression,Token *token,Stack *numberStack,Stack *operatorStack){
		
		//printf("testing111\n");
		//tokenDump(token);
		if(isNumber(token)){
			stackPush(token,numberStack);
		}
		/*
		if(isOperator(token)){
			if(((Operator*)token)->info->affix !=PREFIX)
				tryConvertToPrefix((Operator*)token);
			tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
		}
		*/
		
}
/*******************************************************************************************
 *	This function is to evaluate postfix and infix operator.
 *	This function will stop and return after infix operator is detected.
 *	input  : expression,token,numberStack,operatorStack
 *	output : none
 *	return : function
 *	Throw  : 
********************************************************************************************/

void evaluatePostfixesAndInfix(char *expression,Token *token,Stack *numberStack,Stack *operatorStack){
		
		if(isNumber(token)){
			stackPush(token,numberStack);
		}
		else if(isOperator(token)){
			if(((Operator*)token)->info->affix == INFIX ){
				tryEvaluateOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}else if(((Operator*)token)->info->affix == POSTFIX){
				 tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}else{
				Throw(ERR_EXPECTING_OPERATOR);
			}
		}
}
/*******************************************************************************************
 *	This function is to evaluate the expression which contains numbers and operators and
 *	return the results in number form.
 *	This function is the improved function from the evaluate(char *expression)
 *	Thus, this function can evaluate expression like -2,*2,(((2))), +-+-2... *
 *	input  : expression
 *	output : none
 *	return : ((Number*)token)->value
 *
********************************************************************************************/

int evaluateExpression(char *expression){
	Token *token;
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();

	if(expression ==NULL){
		Throw(ERR_NO_ARGUMENT);
	}
	Text *newText=textNew(expression);
	String *tokenizer = stringNew(newText);
	
	Token *firstToken=getToken(tokenizer);
	if(isOperator(firstToken)){
		if(((Operator*)firstToken)->info->affix !=PREFIX)
			tryConvertToPrefix((Operator*)firstToken);
		stackPush(firstToken,operatorStack);
			if((token=getToken(tokenizer))!=NULL){
				while(token->type !=NUMBER_TOKEN){
				if(isOperator(token)){
					if(((Operator*)token)->info->affix !=PREFIX){
						tryConvertToPrefix((Operator*)token);
						stackPush(token,operatorStack);
						break;
					}
				}
				}
			}
			if(isNumber(token)){
				stackPush(token,numberStack);
				
			}
	}
	if(isNumber(firstToken)){
		stackPush(firstToken,numberStack);
	}
	tokenDump(firstToken);
	
	while((token=getToken(tokenizer))!=NULL){
		
		if(isOperator(firstToken)){
			evaluatePrefixesAndNumber(expression,token,numberStack,operatorStack);
		}
		
		if(isNumber(firstToken)){
			evaluatePostfixesAndInfix(expression,token,numberStack,operatorStack);
		}
		//tokenDump(token);
	}
	
	evaluateAllOperatorOnStack(numberStack,operatorStack);
	Number *result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	if(operatorStack !=NULL){
		destroyStack(operatorStack);
	}
	return result->value;
	
}


