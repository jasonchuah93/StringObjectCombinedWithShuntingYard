#include <stdio.h>
#include <malloc.h>
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

/*
	This function is to push tokens that tokenize from expression to stack 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					  
*/	

//New evaluate

int evaluate(char *expression){
	Token *token;
	Number *result;
	
	Stack *numberStack=createStack();
	Stack *operatorStack=createStack();
	
	Text *newText=textNew(expression);
	String *tokenizer = stringNew(newText);
	
	if(expression ==NULL){	
		Throw(ERR_NO_ARGUMENT);
	}
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

int evaluateExpression(char *expression){
	Token *token;
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
		}else if(isOperator(token)){
			if(((Operator*)token)->info->affix !=PREFIX){
				tryConvertToPrefix((Operator*)token);
				tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}else{
				tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}
		}
	}
	if(operatorStack == NULL){
		operatorPrefixEvaluate(numberStack ,(Operator*)token);
	}else{
		evaluateAllOperatorOnStack(numberStack,operatorStack);
	}
	Number *result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	if(operatorStack !=NULL){
		destroyStack(operatorStack);
	}
	return result->value;
}
