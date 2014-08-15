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
#include "ErrorCode.h"
#include "CException.h"



/**
	Evaluate all operator token on the operator stack that have strictly lower
	precedence than the operator token to be pushed. The evaluation of operators token
	is from the top of stack to bottom
	
	Input :
		stack the operatorStack
		operator the operator to be pushed onto the operator stack 
		
**/

void tryEvaluateOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack){
	Operator *previousToken;
	previousToken=(Operator*)stackPop(operatorStack);
	
	if(previousToken==NULL){
		stackPush(newToken,operatorStack);
	} else{
		while(previousToken!=NULL){
			if(newToken->info->precedence >= previousToken->info->precedence){
				break;
			}
			else{
				operatorEvaluate(numberStack,previousToken);
			}
			previousToken=(Operator*)stackPop(operatorStack);
		}
		
		if(previousToken!=NULL ){
			if(previousToken->info->affix !=PREFIX){
				tryConvertToPrefix(previousToken);
				tokenDump((Token*)previousToken);
				stackPush(previousToken,operatorStack);
			}else if(previousToken->info->affix==INFIX){
				stackPush(previousToken,operatorStack);
			}
		}
		if(previousToken->info->precedence > newToken->info->precedence){
			operatorPrefixEvaluate(numberStack,previousToken);
			previousToken=(Operator*)stackPop(operatorStack);
			stackPush(newToken,operatorStack);
		}else{
			stackPush(newToken,operatorStack);
		}
	}
}

void tryEvaluatePrefixOperatorOnStackThenPush(Operator *newToken,Stack *numberStack,Stack *operatorStack)
{
	Operator *previousToken=(Operator*)stackPop(operatorStack);
	
	if(previousToken == NULL){
		stackPush(newToken,operatorStack);
	}
	else{
		while(previousToken!=NULL)
		{
			if(((Operator*)newToken)->info->id ==CLOSING_BRACKET_OP){
				if(((Operator*)previousToken)->info->id == OPENING_BRACKET_OP){
					operatorPrefixEvaluate(numberStack ,previousToken);
					free(newToken);
					if(((Operator*)previousToken)->info->id == OPENING_BRACKET_OP){
						previousToken=(Operator*)stackPop(operatorStack);
						break;
					}
				}else {
					operatorEvaluate(numberStack,previousToken);
				}
			}else if(newToken->info->precedence >= previousToken->info->precedence || ((Operator*)newToken)->info->id==OPENING_BRACKET_OP ){
				break;
			}
			else{
				operatorEvaluate(numberStack,previousToken);
			}
			previousToken=(Operator*)stackPop(operatorStack);
		}
		if(previousToken!=NULL ){
			stackPush(previousToken,operatorStack);
		}
		if(((Operator*)newToken)->info->id ==OPENING_BRACKET_OP){
			stackPush(newToken,operatorStack);
		}
		
	}
}


void tryConvertToPrefix(Operator *opeToken){
	
	int i;
	OperatorInfo *info=operatorFindAlternateInfoByName(opeToken->info->symbol);
	opeToken->info=info;
	if(opeToken->info == NULL)
	{
		
		Throw(ERR_CANNOT_CONVERT_TO_PREFIX);
	}
}
