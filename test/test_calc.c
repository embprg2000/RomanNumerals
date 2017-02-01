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

START_TEST(test_value2numeral)
{
    char buff[20];
    
    value2numeral(8, buff, 20);
    ck_assert_str_eq(buff, "VIII");
    
    value2numeral(6, buff, 20); 
    ck_assert_str_eq(buff, "VI");
    
    value2numeral(67, buff, 20);
    ck_assert_str_eq(buff, "LXVII");
    
    value2numeral(2991, buff, 20);
    ck_assert_str_eq(buff, "MMCMXCI");
    
    value2numeral(2997, buff, 20);
    ck_assert_str_eq(buff, "MMCMXCVII");
}
END_TEST

// Convert and integer to a roman numeral and
// then convert it back to an integer and compare.
START_TEST(test_conversions)
{
    int i;
    int v; 
    char buff[20];
    
    for (i=1; i<1000; ++i)
    {
        value2numeral(i, buff, 20);
        v = numeral2value(buff);
        ck_assert_int_eq(i, v);
    }
}
END_TEST

START_TEST(test_calculate)
{
    char buff[30];
    
    // 7 - 2 = 5
    ck_assert_str_eq( calculate("VII", '-', "II"), "V");   
    
    // 12 + 50 = 62
    ck_assert_str_eq( calculate("XII", '+', "L"), "LXII");        
    
    // 2997 + 67 = 3064
    ck_assert_str_eq( calculate("MMCMXCVII", '+', "LXVII"), "MMMLXIV");
    
    // 2997 - 67 = 2030
    ck_assert_str_eq( calculate("MMCMXCVII", '-', "LXVII"), "MMCMXXX");
}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_numeral2value;
    TCase *tc_value2numeral;
    TCase *tc_conversions;
    TCase *tc_calculate;

    s = suite_create("Roman Numerals");

    tc_numeral2value = tcase_create("numeral2value");
    tc_value2numeral = tcase_create("value2numeral");
    tc_conversions   = tcase_create("conversions");
    tc_calculate     = tcase_create("calculate");

    tcase_add_test(tc_numeral2value, test_numeral2value);
    tcase_add_test(tc_value2numeral, test_value2numeral);
    tcase_add_test(tc_conversions,   test_conversions);
    tcase_add_test(tc_calculate,     test_calculate);
    
    suite_add_tcase(s, tc_numeral2value);
    suite_add_tcase(s, tc_value2numeral);
    suite_add_tcase(s, tc_conversions);
    suite_add_tcase(s, tc_calculate);        

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
