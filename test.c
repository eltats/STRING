// #include <string.h>
#include <check.h>
#include <stdlib.h>
#include "s21_string.h"

START_TEST(memchr_test) {
  char src1[15] = "1234567890";
  char src2[3] = {'\0', '\0', '\0'};
  char src3[0];
  void *res1, *res2;

  res1 = s21_memchr(src1, '4', 10);
  res2 = memchr(src1, '4', 10);
  ck_assert_ptr_eq(res1, res2);

  res1 = s21_memchr(src2, '\0', 2);
  res2 = memchr(src2, '\0', 2);
  ck_assert_ptr_eq(res1, res2);

  res1 = s21_memchr(src3, 'w', 10);
  res2 = memchr(src3, 'w', 10);
  ck_assert_ptr_eq(res1, res2);
}
END_TEST

START_TEST(memcmp_test) {
  char src1[7] = "Abc";
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

START_TEST(memcpy_test) {
  char src1[15] = "qwert";
  char dst1[3] = "123";
  char src2[11];
  char dst2[11] = "1234567890";
  char src3[3];
  char dst3[3] = "123";
  void *res1, *res2;

  res1 = s21_memcpy(src1, dst1, 3);
  res2 = memcpy(src1, dst1, 3);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memcpy(src2, dst2, 10);
  res2 = memcpy(src2, dst2, 10);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memcpy(src3, dst3, 3);
  res2 = memcpy(src3, dst3, 3);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(memmove_test) {
  char src1[15] = "qwert";
  char dst1[3] = "123";
  char src2[11];
  char dst2[11] = "1234567890";
  char src3[3];
  char dst3[3] = "123";
  void *res1, *res2;

  res1 = s21_memmove(src1, dst1, 3);
  res2 = memmove(src1, dst1, 3);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memmove(src2, dst2, 10);
  res2 = memmove(src2, dst2, 10);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memmove(src3, dst3, 3);
  res2 = memmove(src3, dst3, 3);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(memset_test) {
  char src1[15] = "1234567890";
  char src2[11] = "123";
  char src3[3];
  void *res1, *res2;

  res1 = s21_memset(src1, '1', 11);
  res2 = memset(src1, '1', 11);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memset(src2, '\0', 2);
  res2 = memset(src2, '\0', 2);
  ck_assert_str_eq(res1, res2);

  res1 = s21_memset(src3, 'w', 2);
  res2 = memset(src3, 'w', 2);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(strlen_test) {
  s21_size_t res1, res2;

  res1 = s21_strlen("Lol");
  res2 = strlen("Lol");
  ck_assert_int_eq(res1, res2);

  res1 = s21_strlen("");
  res2 = strlen("");
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strspn_test) {
  s21_size_t res1, res2;

  res1 = s21_strspn("123456789", "312");
  res2 = strspn("123456789", "312");
  ck_assert_int_eq(res1, res2);

  res1 = s21_strspn("", "312");
  res2 = strspn("", "312");
  ck_assert_int_eq(res1, res2);

  res1 = s21_strspn("123456789", "");
  res2 = strspn("123456789", "");
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcspn_test) {
  s21_size_t res1, res2;

  res1 = s21_strcspn("123456789", "9876");
  res2 = strcspn("123456789", "9876");
  ck_assert_int_eq(res1, res2);

  res1 = s21_strcspn("", "9876");
  res2 = strcspn("", "9876");
  ck_assert_int_eq(res1, res2);

  res1 = s21_strcspn("123456789", "");
  res2 = strcspn("123456789", "");
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcmp_test) {
  char str2[4] = "Kek";
  int res1, res2;

  res1 = s21_strcmp("Lol", str2);
  res2 = strcmp("Lol", str2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strncmp_test) {
  char str1[4] = "Lol";
  char str2[4] = "Kek";
  int res1, res2;

  res1 = s21_strncmp(str1, str2, 2);
  res2 = strncmp(str1, str2, 2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(strcpy_test) {
  char str1[4] = "Lol";
  char str2[4] = "Kek";
  char str3[1] = "";
  char str4[1] = "";
  char *result, *result2;

  result = s21_strcpy(str1, str2);
  result2 = strcpy(str1, str2);
  ck_assert_str_eq(result, result2);

  result = s21_strcpy(str3, str4);
  result2 = strcpy(str3, str4);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strncpy_test) {
  char str1[4] = "Lol";
  char str2[4] = "Kek";
  char str3[1] = "";
  char str4[1] = "";
  char *result, *result2;

  result = s21_strncpy(str1, str2, 2);
  result2 = strncpy(str1, str2, 2);
  ck_assert_str_eq(result, result2);

  result = s21_strncpy(str3, str4, 1);
  result2 = strncpy(str3, str4, 1);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strcat_test) {
  char str1[10] = "Lol";
  char str2[4] = "Kek";
  char str3[4] = "";
  char *result, *result2;

  result = s21_strcat(str1, str2);
  result2 = strcat(str1, str2);
  ck_assert_str_eq(result, result2);

  result = s21_strcat(str1, str3);
  result2 = strcat(str1, str3);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strncat_test) {
  char str[8] = "Lol";
  char str2[4] = "Kek";
  char str1[8] = "Lol";
  char *result, *result2;

  result = s21_strncat(str, str2, 2);
  result2 = strncat(str, str2, 2);
  ck_assert_str_eq(result, result2);

  result = s21_strncat(str1, str2, 2);
  result2 = strncat(str1, str2, 2);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strchr_test) {
  char str1[7] = "School";
  char *result, *result2;

  result = s21_strchr(str1, 111);
  result2 = strchr(str1, 111);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strrchr_test) {
  char str1[7] = "School";
  char *result, *result2;

  result = s21_strrchr(str1, 111);
  result2 = strrchr(str1, 111);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strpbrk_test) {
  char str1[7] = "School";
  char str2[4] = "Hole";
  char *result, *result2;

  result = s21_strpbrk(str1, str2);
  result2 = strpbrk(str1, str2);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strerror_test) {
  char *src, *src1, *src2;
  src = s21_strerror(131);
  ck_assert_str_eq(src, strerror(131));
    free(src);

  src1 = s21_strerror(70);
  ck_assert_str_eq(src1, strerror(70));
    free(src1);

  src2 = s21_strerror(-1500);
  ck_assert_str_eq(src2, strerror(-1500));
  free(src2);
}
END_TEST

START_TEST(strstr_test) {
  char str1[7] = "Lol";
  char str2[4] = "ol";
  char str3[7] = "";
  char str4[4] = "";
  char *result, *result2;

  result = s21_strstr(str1, str2);
  result2 = strstr(str1, str2);
  ck_assert_str_eq(result, result2);

  result = s21_strstr(str3, str4);
  result2 = strstr(str3, str4);
  ck_assert_str_eq(result, result2);
}
END_TEST

START_TEST(strtok_test) {
//   char str[] = "School-21";;
//   char *tok1 = s21_strtok(str, "-");
//   char *tok2 = strtok(str, "-");
//   char *tok3 = s21_strtok(str, "");
//   char *tok4 = strtok(str, "");
//   char *tok5 = s21_strtok(str, "oo");
//   char *tok6 = strtok(str, "oo");
//   char *tok7 = s21_strtok(str, "Sc");
//   char *tok8 = strtok(str, "Sc");
//   char *tok9 = s21_strtok(str, "21");
//   char *tok10 = strtok(str, "21");

//   ck_assert_str_eq(tok1, tok2);
//   ck_assert_str_eq(tok3, tok4);
//   ck_assert_str_eq(tok5, tok6);
//   ck_assert_str_eq(tok7, tok8);
//   ck_assert_str_eq(tok9, tok10);
}
END_TEST

START_TEST(s21_sprintf_test) {
  char c[1024] = {};
  int s = -789;
  char strin[1024] = {};
  int st = '6';
  char r[1024] = {};
  double st_e = 9.765625e-05;
  float st_g = 1.111111;
  int st_o = 01234;
  char res[1024] = {};
  char st_s[10] = "qwey";
  unsigned int st_u = 1234;
  int st_x = 0x1234;

  ck_assert_int_eq(s21_sprintf(c, "%d", s), sprintf(c, "%d", s));
  ck_assert_int_eq(s21_sprintf(c, "%16d", s), sprintf(c, "%16d", s));
  ck_assert_int_eq(s21_sprintf(c, "%+16d", s), sprintf(c, "%+16d", s));
  ck_assert_int_eq(s21_sprintf(c, "%-16d", s), sprintf(c, "%-16d", s));
  ck_assert_int_eq(s21_sprintf(c, "%016d", s), sprintf(c, "%016d", s));
  ck_assert_int_eq(s21_sprintf(c, "% 16d", s), sprintf(c, "% 16d", s));

  ck_assert_int_eq(s21_sprintf(c, "%i", s), sprintf(c, "%i", s));
  ck_assert_int_eq(s21_sprintf(c, "%16i", s), sprintf(c, "%16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%+16i", s), sprintf(c, "%+16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%-16i", s), sprintf(c, "%-16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%016i", s), sprintf(c, "%016i", s));
  ck_assert_int_eq(s21_sprintf(c, "% 16i", s), sprintf(c, "% 16i", s));

  s = 0x123;

  ck_assert_int_eq(s21_sprintf(c, "%i", s), sprintf(c, "%i", s));
  ck_assert_int_eq(s21_sprintf(c, "%16i", s), sprintf(c, "%16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%+16i", s), sprintf(c, "%+16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%-16i", s), sprintf(c, "%-16i", s));
  ck_assert_int_eq(s21_sprintf(c, "%016i", s), sprintf(c, "%016i", s));
  ck_assert_int_eq(s21_sprintf(c, "% 16i", s), sprintf(c, "% 16i", s));

  double s1 = -78.8;
  ck_assert_int_eq(s21_sprintf(c, "%f", s1), sprintf(c, "%f", s1));
  ck_assert_int_eq(s21_sprintf(c, "%16f", s1), sprintf(c, "%16f", s1));
  ck_assert_int_eq(s21_sprintf(c, "%+16f", s1), sprintf(c, "%+16f", s1));
  ck_assert_int_eq(s21_sprintf(c, "%-16f", s1), sprintf(c, "%-16f", s1));
  ck_assert_int_eq(s21_sprintf(c, "%016f", s1), sprintf(c, "%016f", s1));
  ck_assert_int_eq(s21_sprintf(c, "% 16f", s1), sprintf(c, "% 16f", s1));
  ck_assert_int_eq(s21_sprintf(c, "%#16f", s1), sprintf(c, "%#16f", s1));

  ck_assert_int_eq(s21_sprintf(strin, "%c", st), sprintf(c, "%c", s));
  ck_assert_int_eq(s21_sprintf(strin, "%-7c", st), sprintf(c, "%-7c", s));


  ck_assert_int_eq(s21_sprintf(res, "%s", st_s), sprintf(res, "%s", st_s));

  unsigned int st_u1 = 123;
  ck_assert_int_eq(s21_sprintf(r, "%u", st_u1), sprintf(r, "%u", st_u1));
  ck_assert_int_eq(s21_sprintf(r, "%16.5u", st_u1),
                   sprintf(r, "%16.5u", st_u1));
  ck_assert_int_eq(s21_sprintf(r, "%-16.5u", st_u1),
                   sprintf(r, "%-16.5u", st_u1));
  ck_assert_int_eq(s21_sprintf(r, "%016.5u", st_u1),
                   sprintf(r, "%016.5u", st_u1));

  ck_assert_int_eq(s21_sprintf(r, "%u", st_u), sprintf(r, "%u", st_u));
  ck_assert_int_eq(s21_sprintf(r, "%16.5u", st_u), sprintf(r, "%16.5u", st_u));
  ck_assert_int_eq(s21_sprintf(r, "%-16.5u", st_u),
                   sprintf(r, "%-16.5u", st_u));
  ck_assert_int_eq(s21_sprintf(r, "%016.5u", st_u),
                   sprintf(r, "%016.5u", st_u));

  int n28 = 0;

  // ck_assert_int_eq(s21_sprintf(r, "%s %n", st_n), sprintf(r, "%s %n", st_n));

//   ck_assert_int_eq(sprintf(r, "%%"), sprintf(r, "%%"));
}
END_TEST

Suite *Suite_create(void) {
  Suite *s21_string = suite_create("s21_string");
  TCase *tcase_test = tcase_create("test");

  tcase_add_test(tcase_test, memchr_test);
  tcase_add_test(tcase_test, memcmp_test);
  tcase_add_test(tcase_test, memcpy_test);
  tcase_add_test(tcase_test, memmove_test);
  tcase_add_test(tcase_test, memset_test);
  tcase_add_test(tcase_test, strlen_test);
  tcase_add_test(tcase_test, strcmp_test);
  tcase_add_test(tcase_test, strncmp_test);
  tcase_add_test(tcase_test, strcpy_test);
  tcase_add_test(tcase_test, strncpy_test);
  tcase_add_test(tcase_test, strcat_test);
  tcase_add_test(tcase_test, strncat_test);
  tcase_add_test(tcase_test, strchr_test);
  tcase_add_test(tcase_test, strrchr_test);
  tcase_add_test(tcase_test, strpbrk_test);
  tcase_add_test(tcase_test, strerror_test);
  tcase_add_test(tcase_test, strtok_test);
  tcase_add_test(tcase_test, strspn_test);
  tcase_add_test(tcase_test, strcspn_test);
  tcase_add_test(tcase_test, strstr_test);
  tcase_add_test(tcase_test, s21_sprintf_test);

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
