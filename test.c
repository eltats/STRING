#include <string.h>
#include <check.h>

#include "s21_string.h"

START_TEST(memcmp_test) {
    char src1[4] = "Abc";
    char dst1[7] = "ABC";
    char src2[3] = "\0";
    char dst2[3] = "\0";
    char src3[6] = "12345";
    char dst3[6] = "12345";

    ck_assert_int_eq(s21_memcmp(src1, dst1, 1), memcmp(src1, dst1, 1));
    ck_assert_int_eq(s21_memcmp(src2, dst2, 1), memcmp(src2, dst2, 1));
    ck_assert_int_eq(s21_memcmp(src3, dst3, 5), memcmp(src3, dst3, 5));
}
END_TEST

Suite *Suite_create(void) {
    Suite *s21_string = suite_create("s21_string");
    TCase *tcase_test = tcase_create("test");

    tcase_add_test(tcase_test, memcmp_test);
    suite_add_tcase(s21_string, tcase_test);

    return s21_string;
}

int main(void) {
    Suite *suite = Suite_create();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);

    int failed_count = srunner_ntests_failed(suite_runner);

    srunner_free(suite_runner);

    return (failed_count != 0) ? 1 : 0;
}
