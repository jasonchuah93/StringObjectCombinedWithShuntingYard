#ifndef __getToken_H
#define __getToken_H

#include "Text.h"
#include "StringObject.h"
#include "Token.h"

Token *getToken(String *str);
int isOperator(Token * unknownToken);
int isNumber(Token * unknownToken);
Token *getTokenise(String *str);

#endif // Token_H