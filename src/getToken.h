#ifndef getToken_H
#define getToken_H

#include "Text.h"
#include "StringObject.h"
#include "Token.h"

Token *getToken(String *str);
int isOperator(Token * unknownToken);
int isNumber(Token * unknownToken);

#endif // Token_H