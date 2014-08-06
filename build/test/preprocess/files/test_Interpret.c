#include "unity.h"
#include "tryEvaluatethenPush.h"
#include "stackForEvaluate.h"
#include "operatorEvaluate.h"
#include "mock_OpCodeDecoder.h"
#include "getToken.h"
#include "createNumberToken.h"
#include "calculateToken.h"
#include "Token.h"
#include "Text.h"
#include "StringObject.h"
#include "String.h"
#include "Stack.h"
#include "LinkedList.h"
#include "Interpret.h"
#include "Evaluate.h"
#include "ErrorCode.h"
#include "CustomTypeAssert.h"
#include "CharSet.h"
#include "CException.h"


void setUp(void){}

void tearDown(void){}





void test_extractValue_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,f,BANKED");

 String *string = stringNew(text);





 int test;



 test = extractValue(string);



 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)35, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",test);

}



void test_extractValue_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)48, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";123 ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)61, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_get_thrown_in_evaluate(void){

 Text *text = textNew("    12+34abc   ,yaomie");

 String *string = stringNew(text);



 char *stringMock = "12+34abc";

 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractValue(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NUMBER_NOT_WELL_FORMED)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)75, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_supports_FsFd_instruction(void){

 Text *text = textNew(" 123  , 321");

 String *string = stringNew(text);



 int test;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)86, UNITY_DISPLAY_STYLE_INT);



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((321)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT);

}



void test_extractDestination_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,BANKED");

 String *string = stringNew(text);



 int test;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d\n",test);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT);

 printf("Answer : %d ",test);

}



void test_extractDestination_should_throw_error_with_empty_argument(void){

 Text *text = textNew("      ; ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)116, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew(";F ");

 String *string = stringNew(text);



 int test,e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)129, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractDestination_should_get_value_from_evaluate(void){

 Text *text = textNew("123,  1    ,BANKED");

 String *string = stringNew(text);





 int test,e;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)141, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)144, UNITY_DISPLAY_STYLE_INT);



}



void test_extractDestination_should_get_value_from_F(void){

 Text *text = textNew("123,  F   ,BANKED");

 String *string = stringNew(text);



 int test,e;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)158, UNITY_DISPLAY_STYLE_INT);



}



void xtest_extractDestination_should_throw_with_invalid_argument(void){

 Text *text = textNew("123,  FA   ,BANKED");

 String *string = stringNew(text);



 char *stringMock;

 stringMock = "123";

 int test,e;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)171, UNITY_DISPLAY_STYLE_INT);



 stringMock = "FA";





 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)179, UNITY_DISPLAY_STYLE_INT);

 }



}



void test_extractAccessBanked_should_return_correct_value_in_integer(void){

 Text *text = textNew("12+34,F,3");

 String *string = stringNew(text);



 char *stringMock = "12+34";

 int test;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((46)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)192, UNITY_DISPLAY_STYLE_INT);



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)195, UNITY_DISPLAY_STYLE_INT);



 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)198, UNITY_DISPLAY_STYLE_INT);

}



void test_extractAccessBanked_should_throw_error_with_empty_argument(void){

 Text *text = textNew(" 123, F,     ; ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;



 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)209, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)213, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)219, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBanked_should_throw_error_with_empty_argument_semicolon(void){

 Text *text = textNew("123,  F   ;");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)236, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);

 }

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractAccessBaked_should_get_value_from_ACCESS(void){

 Text *text = textNew("1+2,  F   ,ACCESS");

 String *string = stringNew(text);



 char *stringMock = "1+2";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)255, UNITY_DISPLAY_STYLE_INT);



 stringMock = "F";

 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)259, UNITY_DISPLAY_STYLE_INT);



 stringMock = "ACCESS";

 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)263, UNITY_DISPLAY_STYLE_INT);



}



void test_extractAccessBanked_should_get_value_from_evaluate(void){

 Text *text = textNew("   123   , 1    ,1+2");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)276, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1";



 test = extractDestination(string);

 UnityAssertEqualNumber((_U_SINT)((1)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)281, UNITY_DISPLAY_STYLE_INT);



 stringMock = "1+2";



 test = extractAccessBanked(string);

 UnityAssertEqualNumber((_U_SINT)((3)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)286, UNITY_DISPLAY_STYLE_INT);



}



void test_extractValue_should_able_to_throw_NO_ARGUMENT_for_both(void){

 Text *text = textNew("123   ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)299, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)304, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)310, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_able_to_throw_EMPTY_ARGUMENT(void){

 Text *text = textNew("123,   , ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)323, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)328, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)334, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_extractValue_should_able_to_throw_NO_ARGUMENT(void){

 Text *text = textNew("123,    ");

 String *string = stringNew(text);



 char *stringMock = "123";

 int test,e;





 test = extractValue(string);

 UnityAssertEqualNumber((_U_SINT)((123)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)347, UNITY_DISPLAY_STYLE_INT);



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractDestination(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_EMPTY_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT);

 }



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  test = extractAccessBanked(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_NO_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_getInstruction_should_get_opCode_RLNCF(){



 instructionTable test;



 test = getInstruction("RLNCF");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x4400)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)367, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((FDA_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)368, UNITY_DISPLAY_STYLE_INT);

}



void test_getInstruction_should_get_opCode_RETLW(){



 instructionTable test;



 test = getInstruction("RETLW");

 UnityAssertEqualNumber((_U_SINT)(_US16)((0x0C00)), (_U_SINT)(_US16)((test.opCode)), (((void *)0)), (_U_UINT)376, UNITY_DISPLAY_STYLE_HEX16);

 UnityAssertEqualNumber((_U_SINT)((K_TYPE)), (_U_SINT)((test.type)), (((void *)0)), (_U_UINT)377, UNITY_DISPLAY_STYLE_INT);

}



void test_interpret_should_able_to_get_correct_value(){

 Text *text = textNew(" ADDWF  0x20, F, BANKED");

 String *string = stringNew(text);



 FDA_CMockExpectAndReturn(384, string, 0x320);

 int test = interpret(string);



 UnityAssertEqualNumber((_U_SINT)((0x2720)), (_U_SINT)((test)), (((void *)0)), (_U_UINT)387, UNITY_DISPLAY_STYLE_INT);



}



void test_interpret_should_throw_an_error_for_unexist_instruction(){

 Text *text = textNew(" SUBWFWFWF  0x20, F, BANKED");

 String *string = stringNew(text);

 int e;



 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)399, UNITY_DISPLAY_STYLE_INT);

 }

}



void test_interpret_should_throw_an_error_for_invalid_input_instruction(){

 Text *text = textNew(" SUBWF  0x20, HAHA, BANKED");

 String *string = stringNew(text);

 int e;



 FDA_CMockExpectAndThrow(408, string, ERR_ILLEGAL_ARGUMENT);

 { jmp_buf *PrevFrame, NewFrame; unsigned int MY_ID = (0); PrevFrame = CExceptionFrames[(0)].pFrame; CExceptionFrames[MY_ID].pFrame = (jmp_buf*)(&NewFrame); CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); if (_setjmp(NewFrame) == 0) { if (&PrevFrame){

  int test = interpret(string);}

 else { } CExceptionFrames[MY_ID].Exception = (0x5A5A5A5A); } else { e = CExceptionFrames[MY_ID].Exception; e=e; } CExceptionFrames[MY_ID].pFrame = PrevFrame; } if (CExceptionFrames[(0)].Exception != (0x5A5A5A5A)){

  UnityAssertEqualNumber((_U_SINT)((ERR_ILLEGAL_ARGUMENT)), (_U_SINT)((e)), (((void *)0)), (_U_UINT)412, UNITY_DISPLAY_STYLE_INT);

 }

}
