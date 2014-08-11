#ifndef __getToken_H
#define __getToken_H

#include "Text.h"
#include "StringObject.h"
#include "Token.h"

Token *getToken(String *str);
int isOperator(Token * unknownToken);
int isNumber(Token * unknownToken);
int testToken(char *expression);

#endif // Token_H