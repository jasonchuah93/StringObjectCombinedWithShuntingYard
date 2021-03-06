/* AUTOGENERATED FILE. DO NOT EDIT. */

//=======Test Runner Used To Run Each Test Below=====
#define RUN_TEST(TestFunc, TestLineNum) \
{ \
  Unity.CurrentTestName = #TestFunc; \
  Unity.CurrentTestLineNumber = TestLineNum; \
  Unity.NumberOfTests++; \
  if (TEST_PROTECT()) \
  { \
    CEXCEPTION_T e; \
    Try { \
      setUp(); \
      TestFunc(); \
    } Catch(e) { TEST_ASSERT_EQUAL_HEX32_MESSAGE(CEXCEPTION_NONE, e, "Unhandled Exception!"); } \
  } \
  if (TEST_PROTECT() && !TEST_IS_IGNORED) \
  { \
    tearDown(); \
  } \
  UnityConcludeTest(); \
}

//=======Automagically Detected Files To Include=====
#include "unity.h"
#include <setjmp.h>
#include <stdio.h>
#include "CException.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

//=======External Functions This Runner Calls=====
extern void setUp(void);
extern void tearDown(void);
extern void test_getToken_should_get_5(void);
extern void test_getToken_should_get_100(void);
extern void test_identifierNew_should_get_return_details(void);
extern void test_identifierNew_should_get_return_details_2(void);
extern void test_operatorNewBySymbol_should_create(void);
extern void test_operatorNewBySymbol_should_create2(void);
extern void test_operatorNewBySymbol_should_retun_NULL(void);
extern void test_operatorNewByID_should_create(void);
extern void test_operatorNewByID_should_create2(void);
extern void test_operatorNewByID_should_retun_NULL(void);
extern void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List(void);
extern void test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List2(void);
extern void test_operatorFindInfoById_should_return_null_if_the_input_is_not_within_the_table_list(void);
extern void test_getToken_sould_return_NumberToken_324(void);
extern void test_getToken_sould_return_NumberToken_123(void);
extern void test_getToken_sould_return_NumberToken_123_without_ending_with_space(void);
extern void test_getToken_sould_return_IdentifierToken_AuCheeLiang(void);
extern void test_getToken_should_return_IdentifierToken_ChiewBingXuan(void);
extern void test_getToken_sould_return_IdentifierToken_AuCheeLiang_without_ending_with_space(void);
extern void test_getToken_should_return_OperatorToken_BITWISE_NOT_OP(void);
extern void test_getToken_should_return_OperatorToken_BITWISE_AND_OP(void);
extern void test_getToken_should_return_OperatorToken_LOGICAL_AND_OP(void);
extern void test_getToken_should_return_OperatorToken_LOGICAL_OR_OP(void);
extern void test_getToken_sould_Throw_an_error_with_mixed_up_number_and_alphabet(void);
extern void test_getToken_sould_Throw_an_error_with_mixed_up_number_and_operator(void);
extern void test_getToken_sould_Throw_an_error_with_mixed_up_all_together(void);
extern void test_getToken_multiple_times_abc_BITWISE_NOT_OP_123(void);
extern void test_getToken_multiple_times_abc_LOGICAL_AND_OP_123(void);
extern void test_getToken_multiple_times_abc_LOGICAL_AND_OP_12a3_should_throw_error(void);
extern void test_getToken_should_get_opening_and_closing_bracket(void);
extern void test_tokenDel_should_not_cause_error(void);
extern void test_getToken_sould_throw_error_mix_Number_Identifier(void);
extern void test_getToken_sould_not_throw_error_mix_Identifier_Number(void);
extern void test_getToken_should_get_1_plus_2(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_Token.c";
  UnityBegin();
  RUN_TEST(test_getToken_should_get_5, 23);
  RUN_TEST(test_getToken_should_get_100, 30);
  RUN_TEST(test_identifierNew_should_get_return_details, 37);
  RUN_TEST(test_identifierNew_should_get_return_details_2, 47);
  RUN_TEST(test_operatorNewBySymbol_should_create, 57);
  RUN_TEST(test_operatorNewBySymbol_should_create2, 68);
  RUN_TEST(test_operatorNewBySymbol_should_retun_NULL, 79);
  RUN_TEST(test_operatorNewByID_should_create, 86);
  RUN_TEST(test_operatorNewByID_should_create2, 97);
  RUN_TEST(test_operatorNewByID_should_retun_NULL, 108);
  RUN_TEST(test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List, 116);
  RUN_TEST(test_operatorFindInfoById_should_get_the_correct_ID_in_the_Table_List2, 127);
  RUN_TEST(test_operatorFindInfoById_should_return_null_if_the_input_is_not_within_the_table_list, 138);
  RUN_TEST(test_getToken_sould_return_NumberToken_324, 147);
  RUN_TEST(test_getToken_sould_return_NumberToken_123, 160);
  RUN_TEST(test_getToken_sould_return_NumberToken_123_without_ending_with_space, 173);
  RUN_TEST(test_getToken_sould_return_IdentifierToken_AuCheeLiang, 185);
  RUN_TEST(test_getToken_should_return_IdentifierToken_ChiewBingXuan, 198);
  RUN_TEST(test_getToken_sould_return_IdentifierToken_AuCheeLiang_without_ending_with_space, 211);
  RUN_TEST(test_getToken_should_return_OperatorToken_BITWISE_NOT_OP, 224);
  RUN_TEST(test_getToken_should_return_OperatorToken_BITWISE_AND_OP, 239);
  RUN_TEST(test_getToken_should_return_OperatorToken_LOGICAL_AND_OP, 254);
  RUN_TEST(test_getToken_should_return_OperatorToken_LOGICAL_OR_OP, 269);
  RUN_TEST(test_getToken_sould_Throw_an_error_with_mixed_up_number_and_alphabet, 284);
  RUN_TEST(test_getToken_sould_Throw_an_error_with_mixed_up_number_and_operator, 297);
  RUN_TEST(test_getToken_sould_Throw_an_error_with_mixed_up_all_together, 310);
  RUN_TEST(test_getToken_multiple_times_abc_BITWISE_NOT_OP_123, 323);
  RUN_TEST(test_getToken_multiple_times_abc_LOGICAL_AND_OP_123, 349);
  RUN_TEST(test_getToken_multiple_times_abc_LOGICAL_AND_OP_12a3_should_throw_error, 375);
  RUN_TEST(test_getToken_should_get_opening_and_closing_bracket, 406);
  RUN_TEST(test_tokenDel_should_not_cause_error, 434);
  RUN_TEST(test_getToken_sould_throw_error_mix_Number_Identifier, 464);
  RUN_TEST(test_getToken_sould_not_throw_error_mix_Identifier_Number, 477);
  RUN_TEST(test_getToken_should_get_1_plus_2, 492);

  return (UnityEnd());
}
