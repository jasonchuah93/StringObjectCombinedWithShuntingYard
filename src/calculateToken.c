#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "Evaluate.h"
#include "Stack.h"
#include "Token.h"
#include "tryEvaluatethenPush.h"
#include "operatorEvaluate.h"
#include "calculateToken.h"
#include "stackForEvaluate.h"
#include "createNumberToken.h"
#include "ErrorCode.h"

int calculate(Operator *opeToken, Number *first, Number *second){
	
	int answer;
	switch(opeToken->info->id)
	{	
		case MUL_OP:
			answer=first->value*second->value;
		break;
		
		case DIV_OP:
			answer=first->value/second->value;
		break;
		
		case ADD_OP:
			answer=first->value+second->value;
		break;	
		
		case SUB_OP:
			answer = first->value - second->value;
				 
		break;
		
		case BITWISE_AND_OP:
			answer=first->value&second->value;
		break;
		
		case BITWISE_OR_OP:
			answer=first->value|second->value;
		break;
		
		case BITWISE_XOR_OP:
			answer=first->value^second->value;
		break;
		
		case MOD_OP:
			answer=first->value%second->value;
		break;
		
		case BITWISE_NOT_OP:
			answer=~first->value;
		break;
		
		case INCREMENT_OP:
			answer=++first->value;
		break;
		
		case DECREMENT_OP:
			answer=--first->value;
		break;
			
		default:
		{
			Throw(UNKNOWN_OPERATOR);
		}
	}
	
	return answer;
}

int prefixCalculate(Operator *opeToken1, Number *first){
	int answer,i;
	switch(opeToken1->info->id)
	{	
		case OPENING_BRACKET_OP:
			answer=(first->value);
		break;
		
		case PLUS_OP:
			answer=+first->value;
		break;
		
		case MINUS_OP:
			answer=-first->value;
		
		break;
		
		case LOGICAL_NOT_OP:
			answer=!first->value;
		break;
		
		default:
		{
			Throw(UNKNOWN_OPERATOR);
		}
	}
	
	return answer;
}