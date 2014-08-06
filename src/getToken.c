#include <stdio.h>
#include <malloc.h>
#include "CException.h"
#include "Token.h"
#include "Text.h"
#include "CharSet.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"



/**
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */
 
Token *getToken(String *str) {
	//1 trim left
	//2 check first character
	//	a	-if a number then extract the number string
	//		-convert into integer
	//		-create number token
	//	b	-if alphabetSet then extract the identifier
	//		-create identifier token
	//	c	-if operator set then extract operator symbol
	//		-create operator token
	
	char charReturn[3];
	Token *tokenReturn;
	String *strReturn;
	
	
	stringTrimLeft(str);
	if(stringLength(str)==0)
		return NULL;		
	
	//Number
	if(stringIsCharAtInSet(str,0,numberSet)){
		strReturn = stringRemoveWordContaining(str,numberSet);
		if(stringIsCharAtInSet(str,0,alphabetSet)){
			free(strReturn);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		else{
			Number *number = numberNew(stringToInteger(strReturn));
			tokenReturn = (Token *)number;
		}
	}
	
	//Identifier
	else if(stringIsCharAtInSet(str,0,alphabetSet)){
		strReturn = stringRemoveWordContaining(str,alphaNumericSet);
		Identifier *identifier = identifierNew(stringSubstringInText(strReturn,0,strReturn->length));
		tokenReturn = (Token *)identifier;
	}
	
	//Operator
	else if(stringIsCharAtInSet(str,0,operatorSet)){
		charReturn[0] = (char )stringRemoveChar(str);
		charReturn[1] = 0;


		if(stringCharAt(str,0) == charReturn[0]){
			if(charReturn[0] == '&'){
				charReturn[0] = '&';
				charReturn[1] = '&';
				charReturn[2] = 0;
			}
			else if(charReturn[0] == '|'){
				charReturn[0] = '|';
				charReturn[1] = '|';
				charReturn[2] = 0;
			}
			else if(charReturn[0] == '+'){
				charReturn[0] = '+';
				charReturn[1] = '+';
				charReturn[2] = 0;
			}
			else if(charReturn[0] == '-'){
				charReturn[0] = '-';
				charReturn[1] = '-';
				charReturn[2] = 0;
			}
			else
				Throw(ERR_NUMBER_NOT_WELL_FORMED);
				
			str->start++;
			str->length--;
		}
		

		Operator *operator = operatorNewBySymbol(charReturn);
		tokenReturn = (Token *)operator;
		
	}
	else
		
		Throw(ERR_NO_ARGUMENT);
		
	free(strReturn);	
	return tokenReturn;
		
}

/*
	This function will determine token is operator or not.
	
	input :
	unknownToken		The token that consists the type.(number, operator)
	
	output:
	none
	
	return:
	0					indicate it is not an operator
	1					indicate it is an operator
*/

int isOperator (Token * unknownToken)
{
	if(unknownToken->type==OPERATOR_TOKEN)
		return 1;
		
	return 0;
}

/*
	This function will determine token is number or not.
	
	input :
	unknownToken		The token that consists the type.(number, operator)
	
	output:
	none
	
	return:
	0					indicate it is not a number
	1					indicate it is a number
*/
int isNumber (Token * unknownToken)
{
	if(unknownToken->type==NUMBER_TOKEN)
		return 1;
		
	return 0;
}