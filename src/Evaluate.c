#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Text.h"
#include "StringObject.h"
#include "Evaluate.h"
#include "String.h"
#include "Stack.h"
#include "Token.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "CustomTypeAssert.h"
#include "malloc.h"
#include "CharSet.h"
#include "CException.h"
#include "ErrorCode.h"

/*
	This function is to push tokens that tokenize from expression to stack 
	
	input  : expression 
	output : none
	return : token 
	Mocking function : 1)initTokenizer(); initialize expression into tokenizer
					   2)getToken();	  get tokens from the tokenizer
					   3)stackPush();   push tokens to number stack or operator stack
					  
*/	

int evaluate(char *expression){
	String *tokenizer;
	Token *token;
	Token *ansToken;
	ErrorCode exception;
	int i;
	int counter=0;
	
	Number *result;
	Stack *numberStack;
	numberStack=createStack();
	Stack *operatorStack;
	operatorStack=createStack();
	if(expression ==NULL){	
		Throw(ERR_ILLEGAL_ARGUMENT);
	}
	
	while((token=getToken(tokenizer))!=NULL){
		
		if(isNumber(token)){
			stackPush(token,numberStack);
		}
		
		else if(isOperator(token))
		{
			if(((Operator*)token)->info->id==OPENING_BRACKET_OP || ((Operator*)token)->info->id==CLOSING_BRACKET_OP)
			{
				tryEvaluatePrefixOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}
			else
			{
				tryEvaluateOperatorOnStackThenPush((Operator*)token,numberStack,operatorStack);
			}	
		}
		counter ++;
	}
	
	if(operatorStack == NULL)
	{
		 operatorPrefixEvaluate(numberStack , (Operator*)token);
	}
	else
	{
		evaluateAllOperatorOnStack(numberStack,operatorStack);
	}
	
	result=(Number*)stackPop(numberStack);
	destroyStack(numberStack);
	
	if(operatorStack !=NULL)
	{
		destroyStack(operatorStack);
	}
	
	printf("Loop needed for each expression to completely evaluate : %d \n",counter);
	return result->value;
	
}