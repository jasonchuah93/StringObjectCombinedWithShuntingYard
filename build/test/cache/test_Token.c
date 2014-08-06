#include "unity.h"
#include "getToken.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void) {}

void tearDown(void) {}



void test_getToken_should_get_5(void) {

 Number *number = numberNew(5);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)17, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)18, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_100(void) {

 Number *number = numberNew(100);



 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)24, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)25, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details(void) {

 int toCompare;

 Text *text = textNew("Yeah");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("Yeah",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details_2(void) {

 int toCompare;

 Text *text = textNew("YaoMie");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("YaoMie",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)45, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("&&");



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)55, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)56, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create2(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("~");



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)66, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)67, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("?");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create(){

 int toCompare;

 Operator *operator = operatorNewByID(BITWISE_NOT_OP);



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)82, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)84, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)85, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create2(){

 int toCompare;

 Operator *operator = operatorNewByID(LOGICAL_AND_OP);



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)96, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewByID(123);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

}





void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List()

{

 int toCompare;

 OperatorInfo *operator = operatorFindInfoByID(LOGICAL_OR_OP);



 toCompare = strcmp(operator->symbol,"||");

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((operator->precedence)), (((void *)0)), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((operator->id)), (((void *)0)), (_U_UINT)114, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List2()

{

 int toCompare;

 OperatorInfo *operator = operatorFindInfoByID(SUB_OP);



 toCompare = strcmp(operator->symbol,"-");

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator->precedence)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator->id)), (((void *)0)), (_U_UINT)125, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)126, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorFindInfoById_should_return_null_if_the_input_is_not_within_the_table_list()

{

 int toCompare;



 OperatorInfo *operator = operatorFindInfoByID(HASH_OP);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_sould_return_NumberToken_324(void){

 int test;

 Text *text = textNew("324 123 435 01010");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)146, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((324)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123 435 01010"), (string), 148, ((void *)0));

}



void test_getToken_sould_return_NumberToken_123(void){

 int test;

 Text *text = textNew("123 me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)160, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" me nem is cheeliang"), (string), 161, ((void *)0));

}



void test_getToken_sould_return_NumberToken_123_without_ending_with_space(void){

 int test;

 Text *text = textNew("123");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 173, ((void *)0));

}



void test_getToken_sould_return_IdentifierToken_AuCheeLiang(void){

 int test;

 Text *text = textNew("AuCheeLiang + ChiewBingXuan = bff");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)184, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("AuCheeLiang"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)185);

 assertStringEqual((" + ChiewBingXuan = bff"), (string), 186, ((void *)0));

}



void test_getToken_should_return_IdentifierToken_ChiewBingXuan(void){

 int test;

 Text *text = textNew("ChiewBingXuan 23+ ChiewB32ringXuan = bff");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)197, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("ChiewBingXuan"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)198);

 assertStringEqual((" 23+ ChiewB32ringXuan = bff"), (string), 199, ((void *)0));

}



void test_getToken_sould_return_IdentifierToken_AuCheeLiang_without_ending_with_space(void){

 int test;

 Text *text = textNew("AuCheeLiang");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)210, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("AuCheeLiang"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)211);

 assertStringEqual((""), (string), 212, ((void *)0));

}



void test_getToken_should_return_OperatorToken_BITWISE_NOT_OP(void){

 int test;

 Text *text = textNew("~ ahahaha hehehe hoho");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)223, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("~"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)224);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)225, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ahahaha hehehe hoho"), (string), 227, ((void *)0));

}



void test_getToken_should_return_OperatorToken_BITWISE_AND_OP(void){

 int test;

 Text *text = textNew("   & ahahaha");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)239);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)240, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)241, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ahahaha"), (string), 242, ((void *)0));

}



void test_getToken_should_return_OperatorToken_LOGICAL_AND_OP(void){

 int test;

 Text *text = textNew("   && 123sdv  we");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)253, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)254);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)256, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123sdv  we"), (string), 257, ((void *)0));

}



void test_getToken_should_return_OperatorToken_LOGICAL_OR_OP(void){

 int test;

 Text *text = textNew("   || 123sdv  we");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)268, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)269);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)271, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123sdv  we"), (string), 272, ((void *)0));

}



void test_getToken_sould_Throw_an_error_with_mixed_up_number_and_alphabet(void){

 int test,e;

 Text *text = textNew(" 1me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_sould_Throw_an_error_with_mixed_up_number_and_operator(void){

 int test,e;

 Text *text = textNew(" 1+1 me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)297, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_sould_Throw_an_error_with_mixed_up_all_together(void){

 int test,e;

 Text *text = textNew("1T@#%@#%@#232fef me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_multiple_times_abc_BITWISE_NOT_OP_123(void){

 Text *text = textNew("  abc ~ 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)321, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)322);

 assertStringEqual((" ~ 123"), (string), 323, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)327, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("~"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)328);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)329, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 331, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)335, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 337, ((void *)0));

}



void test_getToken_multiple_times_abc_LOGICAL_AND_OP_123(void){

 Text *text = textNew("  abc && 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)347, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)348);

 assertStringEqual((" && 123"), (string), 349, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)353, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)354);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)355, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)356, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 357, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)361, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 363, ((void *)0));

}



void test_getToken_multiple_times_abc_LOGICAL_AND_OP_12a3_should_throw_error(void){

 int e;

 Text *text = textNew("  abc && 12a3");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)374, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)375);

 assertStringEqual((" && 12a3"), (string), 376, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)380, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)381);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)382, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)383, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 12a3"), (string), 384, ((void *)0));





 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)390, UNITY_DISPLAY_STYLE_INT);







 }

}



void test_getToken_should_get_opening_and_closing_bracket(void){



 Text *text = textNew("(2)");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)405, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("("), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)406);

 UnityAssertEqualNumber((_U_SINT)((OPENING_BRACKET_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)407, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)408, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("2)"), (string), 409, ((void *)0));

 stringDump(string);

 tokenDump(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)415, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)416, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((")"), (string), 417, ((void *)0));

 stringDump(string);

 tokenDump(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)423, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(")"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)424);

 UnityAssertEqualNumber((_U_SINT)((CLOSING_BRACKET_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)425, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)426, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 427, ((void *)0));

 stringDump(string);

 tokenDump(token);





}

void test_tokenDel_should_not_cause_error(){

 Text *text = textNew("  abc && 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)440, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)441);

 assertStringEqual((" && 123"), (string), 442, ((void *)0));

 tokenDel(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)447, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)448);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)449, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 451, ((void *)0));

 tokenDel(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)456, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)457, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 458, ((void *)0));

 tokenDel(token);



}



void test_getToken_sould_throw_error_mix_Number_Identifier(void){

 int test,e;

 Text *text = textNew("123ABC");

 String *string = stringNew(text);

 Token *token;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)472, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_sould_not_throw_error_mix_Identifier_Number(void){

 int test;

 Text *text = textNew("ABC123");

 String *string = stringNew(text);

 Token *token;





  token = getToken(string);





 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)486, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("ABC123"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)487);

 assertStringEqual((""), (string), 488, ((void *)0));

}
