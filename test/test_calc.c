#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "../src/roman_numerals.h"

START_TEST(test_numeral2value)
{
	//ck_assert_int_eq( numeral2value("V"),  3);	
	ck_assert_int_eq( numeral2value("VI"), 6);
	ck_assert_int_eq( numeral2value("LXVII"),     67);
	ck_assert_int_eq( numeral2value("MMCMXCI"),   2991);
	ck_assert_int_eq( numeral2value("MMCMXCVII"), 2997);
}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Roman Numerals");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_numeral2value);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s  = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
