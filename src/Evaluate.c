#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Evaluate.h"
#include "String.h"
#include "CustomTypeAssert.h"
#include "StringObject.h"
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
	
}