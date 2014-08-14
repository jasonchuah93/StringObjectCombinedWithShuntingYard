#include <stdio.h>
#include <malloc.h>
#include "Token.h"
#include "Text.h"
#include "CharSet.h"
#include "StringObject.h"
#include "getToken.h"
#include "CustomTypeAssert.h"
#include "ErrorCode.h"
#include "CException.h"

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
	Token *tokenReturn = NULL;
	String *strReturn = NULL;
	Number *number = NULL;
	Identifier *identifier = NULL;
	Operator *operator = NULL;
	
	stringTrimLeft(str);
	if(stringLength(str) == 0)
		return NULL;
	
	
	//Number
	if(stringIsCharAtInSet(str,0,numberSet)){
		strReturn = stringRemoveWordContaining(str,numberSet);
		if(stringIsCharAtInSet(str,0,alphabetSet)){
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		else{
			number = numberNew(stringToInteger(strReturn));
			tokenReturn = (Token *)number;
			stringDel(strReturn);
		}
	}
	
	//Identifier
	else if(stringIsCharAtInSet(str,0,alphabetSet)){
		strReturn = stringRemoveWordContaining(str,alphaNumericSet);
		identifier = identifierNew(stringSubstringInText(strReturn,0,strReturn->length));
		tokenReturn = (Token *)identifier;
		stringDel(strReturn);
	}
	
	//Operator
	else if(stringIsCharAtInSet(str,0,operatorSet)){
		charReturn[0] = (char )stringRemoveChar(str);
		charReturn[1] = 0;
		
		if(stringCharAt(str,0) == charReturn[0] && stringLength(str) != 0){
			if(charReturn[0] == '&'){
				charReturn[0] = '&';
				charReturn[1] = '&';
				charReturn[2] = 0;
				str->start++;
				str->length--;
			}
			else if(charReturn[0] == '|'){
				charReturn[0] = '|';
				charReturn[1] = '|';
				charReturn[2] = 0;
				str->start++;
				str->length--;
			}
		}
		operator = operatorNewBySymbol(charReturn);
		tokenReturn = (Token *)operator;
		
	}
	else
		Throw(ERR_ILLEGAL_ARGUMENT);
		
	
	return tokenReturn;
}
/**
 * This function served as a temporary function use on for my evaluate(char *expression) and 
 * evaluateExpression (char *expression) function while James fixing his getToken.
 * Once James fix his getToken function, I will use back his getToken function.
 * Return the one token from the String. The String is updated.
 * If the string is empty, NULL is return.
 *
 * Input:
 *   str  is the String object
 *
 * Possible returned token:
 *    Number, Operator, and Identifier tokens
 */
Token *getTokenise(String *str) {
	Number *num;
	Operator *op;
	Identifier *id;
	int number;
	int length;
	String *stringRemoveWordContain = NULL;
	Token *newToken;
	char opeToken[3];
	Text *strSubInText;
	
	
	stringTrimLeft(str);
	//Number Token
	if(stringCharAtInSet(str,0,numberSet))
	{
		stringRemoveWordContain = stringRemoveWordContaining(str,numberSet);
		
		if(isSpace(stringCharAt(str,0)) || str->length==0 ||str->start!=0)
		{
			number = stringToInteger(stringRemoveWordContain);
			num = numberNew(number);
			newToken = (Token*)num;
			
		}
		else{
			free(stringRemoveWordContain);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		return newToken;
	}	
	
	
	//Operator Token
	else if(stringCharAtInSet(str,0,operatorSet))
	{
		opeToken[0]=(char)stringRemoveChar(str);
		opeToken[1]=0;
		//This condition need to place before isSpace condition as the opeToken[0] will first look for the opeToken[1] if the user input '&' or '|'
		
		if(isSpace(stringCharAt(str,0)) || (str->length==0) || (str->start!=0))
		{
				if(opeToken[0]=='&')
				{
					opeToken[1]='&';
					opeToken[2]=0;
					str->start++;
					str->length--;
				}
				else if(opeToken[0]=='|')
				{
					opeToken[1]='|';
					opeToken[2]=0;
					str->start++;
					str->length--;
				}
				
			op = operatorNewBySymbol(opeToken);	
			newToken = (Token*)op;
			
		}
		else
		{	
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}
		return newToken;
	}
	
	//Identifier Token
	
	else if(stringCharAtInSet(str,0,alphabetSet))
	{
		stringRemoveWordContain = stringRemoveWordContaining(str,alphabetSet);
		
		
		if(isSpace(stringCharAt(str,0))||str->length==0 ||str->start!=0 )
		{
			strSubInText = stringSubstringInText(stringRemoveWordContain,stringRemoveWordContain->start,stringRemoveWordContain->length);
			id = identifierNew(strSubInText);
			newToken = (Token*)id;
			
		}
		
		else
		{
			free(stringRemoveWordContain);
			Throw(ERR_NUMBER_NOT_WELL_FORMED);
		}	
		return newToken;
	}
	
	
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
	{
		return 1;
	}
	else
	{
		return 0;
	}
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
	{	
		return 1;
	}
	else	
	{
		return 0;
	}
}

