#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "getToken.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Evaluate.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void) {}

void tearDown(void) {}





void test_getToken_should_get_5(void) {

 Number *number = numberNew(5);



 UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)26, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)27, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_should_get_100(void) {

 Number *number = numberNew(100);



 UnityAssertEqualNumber((_U_SINT)((100)), (_U_SINT)((number->value)), (((void *)0)), (_U_UINT)33, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((number->type)), (((void *)0)), (_U_UINT)34, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details(void) {

 int toCompare;

 Text *text = textNew("Yeah");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("Yeah",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)43, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)44, UNITY_DISPLAY_STYLE_INT);

}



void test_identifierNew_should_get_return_details_2(void) {

 int toCompare;

 Text *text = textNew("YaoMie");

 Identifier *identifier = identifierNew(text);



 toCompare = strcmp("YaoMie",identifier->name->string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((identifier->type)), (((void *)0)), (_U_UINT)54, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("&&");



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)63, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)64, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)65, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_create2(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("~");



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)73, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)74, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)76, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewBySymbol_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewBySymbol("?");



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)83, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create(){

 int toCompare;

 Operator *operator = operatorNewByID(BITWISE_NOT_OP);



 toCompare = strcmp(operator->info->symbol,"~");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)92, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)93, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)94, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_create2(){

 int toCompare;

 Operator *operator = operatorNewByID(LOGICAL_AND_OP);



 toCompare = strcmp(operator->info->symbol,"&&");

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((operator->type)), (((void *)0)), (_U_UINT)102, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((operator->info->precedence)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((operator->info->id)), (((void *)0)), (_U_UINT)104, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)105, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorNewByID_should_retun_NULL(){

 int toCompare;

 Operator *operator = operatorNewByID(123);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)112, UNITY_DISPLAY_STYLE_INT);

}





void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List()

{

 int toCompare;

 OperatorInfo *operator = operatorFindInfoByID(LOGICAL_OR_OP);



 toCompare = strcmp(operator->symbol,"||");

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((operator->precedence)), (((void *)0)), (_U_UINT)122, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((operator->id)), (((void *)0)), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)124, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List2()

{

 int toCompare;

 OperatorInfo *operator = operatorFindInfoByID(SUB_OP);



 toCompare = strcmp(operator->symbol,"-");

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((operator->precedence)), (((void *)0)), (_U_UINT)133, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((SUB_OP)), (_U_SINT)((operator->id)), (((void *)0)), (_U_UINT)134, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((toCompare)), (((void *)0)), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT);

}



void test_operatorFindInfoById_should_return_null_if_the_input_is_not_within_the_table_list()

{

 int toCompare;



 OperatorInfo *operator = operatorFindInfoByID(HASH_OP);



 UnityAssertEqualNumber((_U_SINT)((((void *)0))), (_U_SINT)((operator)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);

}



void test_getToken_sould_return_NumberToken_324(void){

 int test;

 Text *text = textNew("324 123 435 01010");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((324)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123 435 01010"), (string), 157, ((void *)0));

}



void test_getToken_sould_return_NumberToken_123(void){

 int test;

 Text *text = textNew("123 me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)168, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)169, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" me nem is cheeliang"), (string), 170, ((void *)0));

}



void test_getToken_sould_return_NumberToken_123_without_ending_with_space(void){

 int test;

 Text *text = textNew("123");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)180, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 182, ((void *)0));

}



void test_getToken_sould_return_IdentifierToken_AuCheeLiang(void){

 int test;

 Text *text = textNew("AuCheeLiang + ChiewBingXuan = bff");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)193, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("AuCheeLiang"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)194);

 assertStringEqual((" + ChiewBingXuan = bff"), (string), 195, ((void *)0));

}



void test_getToken_should_return_IdentifierToken_ChiewBingXuan(void){

 int test;

 Text *text = textNew("ChiewBingXuan 23+ ChiewB32ringXuan = bff");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)206, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("ChiewBingXuan"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)207);

 assertStringEqual((" 23+ ChiewB32ringXuan = bff"), (string), 208, ((void *)0));

}



void test_getToken_sould_return_IdentifierToken_AuCheeLiang_without_ending_with_space(void){

 int test;

 Text *text = textNew("AuCheeLiang");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("AuCheeLiang"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)220);

 assertStringEqual((""), (string), 221, ((void *)0));

}



void test_getToken_should_return_OperatorToken_BITWISE_NOT_OP(void){

 int test;

 Text *text = textNew("~ ahahaha hehehe hoho");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("~"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)233);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)234, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)235, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ahahaha hehehe hoho"), (string), 236, ((void *)0));

}



void test_getToken_should_return_OperatorToken_BITWISE_AND_OP(void){

 int test;

 Text *text = textNew("   & ahahaha");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)247, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)248);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)249, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((60)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" ahahaha"), (string), 251, ((void *)0));

}



void test_getToken_should_return_OperatorToken_LOGICAL_AND_OP(void){

 int test;

 Text *text = textNew("   && 123sdv  we");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)263);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)264, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)265, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123sdv  we"), (string), 266, ((void *)0));

}



void test_getToken_should_return_OperatorToken_LOGICAL_OR_OP(void){

 int test;

 Text *text = textNew("   || 123sdv  we");

 String *string = stringNew(text);

 Token *token;



 token = getToken(string);



 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)277, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("||"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)278);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_OR_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)279, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((20)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123sdv  we"), (string), 281, ((void *)0));

}



void test_getToken_sould_Throw_an_error_with_mixed_up_number_and_alphabet(void){

 int test,e;

 Text *text = textNew(" 1me nem is cheeliang");

 String *string = stringNew(text);

 Token *token;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)293, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)306, UNITY_DISPLAY_STYLE_INT);

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

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_multiple_times_abc_BITWISE_NOT_OP_123(void){

 Text *text = textNew("  abc ~ 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)330, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)331);

 assertStringEqual((" ~ 123"), (string), 332, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("~"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)337);

 UnityAssertEqualNumber((_U_SINT)((BITWISE_NOT_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)338, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((150)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)339, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 340, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)344, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)345, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 346, ((void *)0));

}



void test_getToken_multiple_times_abc_LOGICAL_AND_OP_123(void){

 Text *text = textNew("  abc && 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)356, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)357);

 assertStringEqual((" && 123"), (string), 358, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)362, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)363);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)364, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)365, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 366, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)370, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)371, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 372, ((void *)0));

}



void test_getToken_multiple_times_abc_LOGICAL_AND_OP_12a3_should_throw_error(void){

 int e;

 Text *text = textNew("  abc && 12a3");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)383, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)384);

 assertStringEqual((" && 12a3"), (string), 385, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)389, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)390);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)392, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 12a3"), (string), 393, ((void *)0));





 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

 token = getToken(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

 UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)399, UNITY_DISPLAY_STYLE_INT);







 }

}



void test_getToken_should_get_opening_and_closing_bracket(void){



 Text *text = textNew("(2)");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)414, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("("), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)415);

 UnityAssertEqualNumber((_U_SINT)((OPENING_BRACKET_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)416, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((10)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)417, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("2)"), (string), 418, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)422, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)423, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((")"), (string), 424, ((void *)0));





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)428, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)(")"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)429);

 UnityAssertEqualNumber((_U_SINT)((CLOSING_BRACKET_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)430, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)431, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 432, ((void *)0));

}

void test_tokenDel_should_not_cause_error(){

 Text *text = textNew("  abc && 123");

 String *string = stringNew(text);

 Token *token;





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)441, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("abc"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)442);

 assertStringEqual((" && 123"), (string), 443, ((void *)0));

 tokenDel(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)448, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("&&"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)449);

 UnityAssertEqualNumber((_U_SINT)((LOGICAL_AND_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)450, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((30)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)451, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((" 123"), (string), 452, ((void *)0));

 tokenDel(token);





 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)457, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)458, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 459, ((void *)0));

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

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)473, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getToken_sould_not_throw_error_mix_Identifier_Number(void){

 int test;

 Text *text = textNew("ABC123");

 String *string = stringNew(text);

 Token *token;





  token = getToken(string);





 UnityAssertEqualNumber((_U_SINT)((IDENTIFIER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)487, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("ABC123"), (const char*)(((Identifier *)token)->name->string), (((void *)0)), (_U_UINT)488);

 assertStringEqual((""), (string), 489, ((void *)0));

}



void test_getToken_should_get_1_plus_2(void){

 int test;

 char temp[]="1+2";

 Text *text = textNew(temp);

 String *string = stringNew(text);



 Token *token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)499, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)500, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("+2"), (string), 501, ((void *)0));



 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((OPERATOR_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)504, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualString((const char*)("+"), (const char*)(((Operator *)token)->info->symbol), (((void *)0)), (_U_UINT)505);

 UnityAssertEqualNumber((_U_SINT)((ADD_OP)), (_U_SINT)((((Operator *)token)->info->id)), (((void *)0)), (_U_UINT)506, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((80)), (_U_SINT)((((Operator *)token)->info->precedence)), (((void *)0)), (_U_UINT)507, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual(("2"), (string), 508, ((void *)0));



 token = getToken(string);

 UnityAssertEqualNumber((_U_SINT)((NUMBER_TOKEN)), (_U_SINT)((token->type)), (((void *)0)), (_U_UINT)511, UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((_U_SINT)((2)), (_U_SINT)((((Number *)token)->value)), (((void *)0)), (_U_UINT)512, UNITY_DISPLAY_STYLE_INT);

 assertStringEqual((""), (string), 513, ((void *)0));



}



void test_testToken(void)

{



 printf("Evaluate function\n");

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((evaluateExpression("1+2"))), (((void *)0)), (_U_UINT)521, UNITY_DISPLAY_STYLE_INT);

}
