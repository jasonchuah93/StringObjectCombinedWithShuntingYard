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
extern void test_stringNew_should_create_string_with_dynamic_text(void);
extern void test_stringNew_should_create_string_with_dynamic_text_2(void);
extern void test_stringNew_should_create_string_with_dynamic_text_3(void);
extern void test_stringNew_should_create_string_with_static_text(void);
extern void test_stringAssign_should_increase_reference(void);
extern void test_stringDel_should_delete_and_reduce_text_reference(void);
extern void test_stringDel_should_delete_and_not_reduce_text_reference(void);
extern void test_stringSkip_should_skip(void);
extern void test_stringSkip_should_overload_and_stop_at_Null(void);
extern void test_stringTrimLeft(void);
extern void test_stringTrimLeft2(void);
extern void test_stringTrimRight(void);
extern void test_stringTrimRight2(void);
extern void test_stringTrim_should_trim_both_sides(void);
extern void test_stringTrim_should_trim_both_sides2(void);
extern void test_stringTrim_should_trim_both_sides3(void);
extern void test_all(void);
extern void test_stringRemoveChar_should_remove_w(void);
extern void test_stringRemoveChar_should_remove_spacing(void);
extern void test_stringRemoveChar_should_return_negative_one_after_deletion(void);
extern void test_stringRemoveChar_should_return_negative_one_with_NULL_input(void);
extern void test_stringLength_should_get_6(void);
extern void test_stringLength_should_get_16(void);
extern void test_stringRemoveWordNotContaining_remove_abcd(void);
extern void test_stringRemoveWordNotContaining_remove_abcd_static(void);
extern void test_stringRemoveWordNotContaining_remove_ww(void);
extern void test_stringRemoveWordNotContaining_remove_ww_static(void);
extern void test_stringRemoveWordNotContaining_remove_nothing(void);
extern void test_stringRemoveWordContaining_remove_ab(void);
extern void test_stringRemoveWordContaining_remove_ab_static(void);
extern void test_stringRemoveWordContaining_remove_abc(void);
extern void test_stringRemoveWordContaining_remove_abc_static(void);
extern void test_stringRemoveWordContaining_remove_nothing(void);
extern void test_stringIsEqual_should_return_equal(void);
extern void test_stringIsEqual_should_return_equal_static(void);
extern void test_stringIsEqual_should_return_not_equal(void);
extern void test_stringIsEqual_should_return_not_equal_static(void);
extern void test_stringIsEqualCaseInsensitive_should_equal(void);
extern void test_stringIsEqualCaseInsensitive_should_equal_with_different_start(void);
extern void test_stringIsEqualCaseInsensitive_should_not_equal(void);
extern void test_stringIsEqualCaseInsensitive_should_equal_static(void);
extern void test_extra_to_solve_problem_1(void);
extern void test_extra_to_solve_problem_2(void);
extern void test_extra_to_solve_problem_3(void);
extern void test_stringCharAt_should_return_index(void);
extern void test_stringCharAt_should_return_index_static(void);
extern void test_stringCharAt_should_return_negative_1_over_string_length(void);
extern void test_stringCharAt_should_return_negative_1_over_string_length_static(void);
extern void test_stringCharAt_should_return_negative_1_negative_input(void);
extern void test_stringCharAt_should_return_negative_1_negative_input_static(void);
extern void test_stringIsCharAtInSet_should_return_1_contain_in_set(void);
extern void test_stringIsCharAtInSet_should_return_0_error_input(void);
extern void test_stringIsCharAtInSet_should_return_0_not_found_in_set(void);
extern void test_stringSubstringInChar_should_crop_out_123(void);
extern void test_stringSubstringInChar_should_crop_out_Stone(void);
extern void test_stringSubstringInChar_should_crop_out_1(void);
extern void test_stringSubstringInText_return_Text_1(void);
extern void test_stringSubstringInText_return_Text_abcd(void);
extern void test_stringToInteger_should_get_1234(void);
extern void test_stringToInteger_should_get_23(void);
extern void test_stringToInteger_should_get_5555(void);


//=======Test Reset Option=====
void resetTest()
{
  tearDown();
  setUp();
}


//=======MAIN=====
int main(void)
{
  Unity.TestFile = "test_StringObject.c";
  UnityBegin();
  RUN_TEST(test_stringNew_should_create_string_with_dynamic_text, 88);
  RUN_TEST(test_stringNew_should_create_string_with_dynamic_text_2, 101);
  RUN_TEST(test_stringNew_should_create_string_with_dynamic_text_3, 114);
  RUN_TEST(test_stringNew_should_create_string_with_static_text, 127);
  RUN_TEST(test_stringAssign_should_increase_reference, 139);
  RUN_TEST(test_stringDel_should_delete_and_reduce_text_reference, 148);
  RUN_TEST(test_stringDel_should_delete_and_not_reduce_text_reference, 159);
  RUN_TEST(test_stringSkip_should_skip, 170);
  RUN_TEST(test_stringSkip_should_overload_and_stop_at_Null, 178);
  RUN_TEST(test_stringTrimLeft, 186);
  RUN_TEST(test_stringTrimLeft2, 194);
  RUN_TEST(test_stringTrimRight, 204);
  RUN_TEST(test_stringTrimRight2, 212);
  RUN_TEST(test_stringTrim_should_trim_both_sides, 220);
  RUN_TEST(test_stringTrim_should_trim_both_sides2, 228);
  RUN_TEST(test_stringTrim_should_trim_both_sides3, 236);
  RUN_TEST(test_all, 244);
  RUN_TEST(test_stringRemoveChar_should_remove_w, 265);
  RUN_TEST(test_stringRemoveChar_should_remove_spacing, 276);
  RUN_TEST(test_stringRemoveChar_should_return_negative_one_after_deletion, 287);
  RUN_TEST(test_stringRemoveChar_should_return_negative_one_with_NULL_input, 298);
  RUN_TEST(test_stringLength_should_get_6, 309);
  RUN_TEST(test_stringLength_should_get_16, 318);
  RUN_TEST(test_stringRemoveWordNotContaining_remove_abcd, 327);
  RUN_TEST(test_stringRemoveWordNotContaining_remove_abcd_static, 339);
  RUN_TEST(test_stringRemoveWordNotContaining_remove_ww, 352);
  RUN_TEST(test_stringRemoveWordNotContaining_remove_ww_static, 367);
  RUN_TEST(test_stringRemoveWordNotContaining_remove_nothing, 382);
  RUN_TEST(test_stringRemoveWordContaining_remove_ab, 395);
  RUN_TEST(test_stringRemoveWordContaining_remove_ab_static, 408);
  RUN_TEST(test_stringRemoveWordContaining_remove_abc, 421);
  RUN_TEST(test_stringRemoveWordContaining_remove_abc_static, 434);
  RUN_TEST(test_stringRemoveWordContaining_remove_nothing, 447);
  RUN_TEST(test_stringIsEqual_should_return_equal, 460);
  RUN_TEST(test_stringIsEqual_should_return_equal_static, 474);
  RUN_TEST(test_stringIsEqual_should_return_not_equal, 488);
  RUN_TEST(test_stringIsEqual_should_return_not_equal_static, 502);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_equal, 516);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_equal_with_different_start, 527);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_not_equal, 540);
  RUN_TEST(test_stringIsEqualCaseInsensitive_should_equal_static, 551);
  RUN_TEST(test_extra_to_solve_problem_1, 564);
  RUN_TEST(test_extra_to_solve_problem_2, 574);
  RUN_TEST(test_extra_to_solve_problem_3, 586);
  RUN_TEST(test_stringCharAt_should_return_index, 601);
  RUN_TEST(test_stringCharAt_should_return_index_static, 609);
  RUN_TEST(test_stringCharAt_should_return_negative_1_over_string_length, 617);
  RUN_TEST(test_stringCharAt_should_return_negative_1_over_string_length_static, 625);
  RUN_TEST(test_stringCharAt_should_return_negative_1_negative_input, 633);
  RUN_TEST(test_stringCharAt_should_return_negative_1_negative_input_static, 641);
  RUN_TEST(test_stringIsCharAtInSet_should_return_1_contain_in_set, 649);
  RUN_TEST(test_stringIsCharAtInSet_should_return_0_error_input, 657);
  RUN_TEST(test_stringIsCharAtInSet_should_return_0_not_found_in_set, 667);
  RUN_TEST(test_stringSubstringInChar_should_crop_out_123, 677);
  RUN_TEST(test_stringSubstringInChar_should_crop_out_Stone, 687);
  RUN_TEST(test_stringSubstringInChar_should_crop_out_1, 697);
  RUN_TEST(test_stringSubstringInText_return_Text_1, 707);
  RUN_TEST(test_stringSubstringInText_return_Text_abcd, 717);
  RUN_TEST(test_stringToInteger_should_get_1234, 727);
  RUN_TEST(test_stringToInteger_should_get_23, 735);
  RUN_TEST(test_stringToInteger_should_get_5555, 745);

  return (UnityEnd());
}
