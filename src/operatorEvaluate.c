#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "Stack.h"
#include "StringObject.h"
#include "Token.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "createNumberToken.h" 
#include "LinkedList.h"
#include "stackForEvaluate.h"
#include <malloc.h>

/**
	Evaluate all operators on the operator stack, with top of stack 
	operator being evaluated first.
	
	Input :
		stack the operatorStack
**/

void operatorEvaluate(Stack *numberStack , Operator *opeToken){
	
	Number *num1;
	Number *num2;
	Token *token1; 
	Token *token2; 
	int answer; 
	Token *answerToken; 
	
	if(opeToken->info->id==OPENING_BRACKET_OP)
	{
		token1=(Token*)stackPop(numberStack); 
		num1=(Number*)token1; 
		answer = prefixCalculate(opeToken,num1); 
		answerToken=createNumberToken(answer);
		stackPush(answerToken,numberStack);
	}
	else if(opeToken->info->id==OPENING_BRACKET_OP)
	{
		token1=(Token*)stackPop(numberStack); 
		num1=(Number*)token1; 
		token2=(Token*)stackPop(numberStack); 
		if(token2!=NULL){
			num2=(Number*)token2;
			answer = calculate(opeToken,num2,num1); 
			answerToken=createNumberToken(answer);
			stackPush(answerToken,numberStack);
		}
		else
		{
			answer = prefixCalculate(opeToken,num1); 
			answerToken=createNumberToken(answer);
			stackPush(answerToken,numberStack);
		}
	}
	else 
	{
		token1=(Token*)stackPop(numberStack); 
		num1=(Number*)token1;
		token2=(Token*)stackPop(numberStack); 
		if(token2!=NULL){
			num2=(Number*)token2;
			answer = calculate(opeToken,num2,num1); 
			answerToken=createNumberToken(answer);
			stackPush(answerToken,numberStack);
		}
		else
		{
			answer = prefixCalculate(opeToken,num1); 
			answerToken=createNumberToken(answer);
			stackPush(answerToken,numberStack);
		}
	}
	
	
}	

void operatorPrefixEvaluate(Stack *numberStack , Operator *opeToken1){
	
	Number *num1;
	Token *token1; 
	int answer; 
	Token *answerToken; 
	
	token1=(Token*)stackPop(numberStack); 
	num1=(Number*)token1; 
	answer = prefixCalculate(opeToken1,num1); 
	answerToken=createNumberToken(answer);
	stackPush(answerToken,numberStack);
	
	
}	


/**
	Evaluate all operators on the operator stack, with top of stack 
	operator being evaluated first.
	
	Input :
		stack the operatorStack
**/

void evaluateAllOperatorOnStack(Stack *numberStack,Stack *operatorStack){
	
	Operator *opeToken;
	
	while((opeToken=stackPop(operatorStack))!=NULL)
	{
		operatorEvaluate(numberStack,opeToken);
	}
}

void evaluatePrefixOperatorOnStack(Stack *numberStack,Stack *operatorStack){
	
	Operator *opeToken;
	
	while((opeToken=stackPop(operatorStack))==NULL)
	{
		operatorPrefixEvaluate(numberStack,opeToken);
		
	}

	
}
