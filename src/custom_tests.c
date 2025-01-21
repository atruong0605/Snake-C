#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asserts.h"
// Necessary due to static functions in state.c
#include "state.c"

/* Look at asserts.c for some helpful assert functions */

int greater_than_forty_two(int x) {
  return x > 42;
}

bool is_vowel(char c) {
  char* vowels = "aeiouAEIOU";
  for (int i = 0; i < strlen(vowels); i++) {
    if (c == vowels[i]) {
      return true;
    }
  }
  return false;
}

/*
  Example 1: Returns true if all test cases pass. False otherwise.
    The function greater_than_forty_two(int x) will return true if x > 42. False otherwise.
    Note: This test is NOT comprehensive
*/
bool test_greater_than_forty_two() {
  int testcase_1 = 42;
  bool output_1 = greater_than_forty_two(testcase_1);
  if (!assert_false("output_1", output_1)) {
    return false;
  }

  int testcase_2 = -42;
  bool output_2 = greater_than_forty_two(testcase_2);
  if (!assert_false("output_2", output_2)) {
    return false;
  }

  int testcase_3 = 4242;
  bool output_3 = greater_than_forty_two(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  return true;
}

/*
  Example 2: Returns true if all test cases pass. False otherwise.
    The function is_vowel(char c) will return true if c is a vowel (i.e. c is a,e,i,o,u)
    and returns false otherwise
    Note: This test is NOT comprehensive
*/
bool test_is_vowel() {
  char testcase_1 = 'a';
  bool output_1 = is_vowel(testcase_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }

  char testcase_2 = 'e';
  bool output_2 = is_vowel(testcase_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }

  char testcase_3 = 'i';
  bool output_3 = is_vowel(testcase_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char testcase_4 = 'o';
  bool output_4 = is_vowel(testcase_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char testcase_5 = 'u';
  bool output_5 = is_vowel(testcase_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }

  char testcase_6 = 'k';
  bool output_6 = is_vowel(testcase_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }

  return true;
}

/* Task 4.1 */

bool test_is_tail() {
  // TODO: Implement this function.
  char test_1 = 'w';
  bool output_1 = is_tail(test_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }
  char test_2 = 'a';
  bool output_2 = is_tail(test_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }
  char test_3 = 's';
  bool output_3 = is_tail(test_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char test_4 = 'd';
  bool output_4 = is_tail(test_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char test_5 = 'W';
  bool output_5 = is_tail(test_5);
  if (!assert_false("output_5", output_5)) {
    return false;
  }
  char test_6 = 'A';
  bool output_6 = is_tail(test_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }
  char test_7 = 'S';
  bool output_7 = is_tail(test_7);
  if (!assert_false("output_7", output_7)) {
    return false;
  }
  char test_8 = 'D';
  bool output_8 = is_tail(test_8);
  if (!assert_false("output_8", output_8)) {
    return false;
  }
  char test_9 = '^';
  bool output_9 = is_tail(test_9);
  if (!assert_false("output_9", output_9)) {
    return false;
  }
  char test_10 = '<';
  bool output_10 = is_tail(test_10);
  if (!assert_false("output_10", output_10)) {
    return false;
  }
  char test_11 = 'v';
  bool output_11 = is_tail(test_11);
  if (!assert_false("output_11", output_11)) {
    return false;
  }
  char test_12 = '>';
  bool output_12 = is_tail(test_12);
  if (!assert_false("output_12", output_12)) {
    return false;
  }
  char test_13 = 'x';
  bool output_13 = is_tail(test_13);
  if (!assert_false("output_13", output_13)) {
    return false;
  }
  return true;
}

bool test_is_head() {
  // TODO: Implement this function.
  char test_1 = 'W';
  bool output_1 = is_head(test_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }
  char test_2 = 'A';
  bool output_2 = is_head(test_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }
  char test_3 = 'S';
  bool output_3 = is_head(test_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char test_4 = 'D';
  bool output_4 = is_head(test_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char test_5 = 'w';
  bool output_5 = is_head(test_5);
  if (!assert_false("output_5", output_5)) {
    return false;
  }
  char test_6 = 'a';
  bool output_6 = is_head(test_6);
  if (!assert_false("output_6", output_6)) {
    return false;
  }
  char test_7 = 's';
  bool output_7 = is_head(test_7);
  if (!assert_false("output_7", output_7)) {
    return false;
  }
  char test_8 = 'd';
  bool output_8 = is_head(test_8);
  if (!assert_false("output_8", output_8)) {
    return false;
  }
  char test_9 = '^';
  bool output_9 = is_head(test_9);
  if (!assert_false("output_9", output_9)) {
    return false;
  }
  char test_10 = '<';
  bool output_10 = is_head(test_10);
  if (!assert_false("output_10", output_10)) {
    return false;
  }
  char test_11 = 'v';
  bool output_11 = is_head(test_11);
  if (!assert_false("output_11", output_11)) {
    return false;
  }
  char test_12 = '>';
  bool output_12 = is_head(test_12);
  if (!assert_false("output_12", output_12)) {
    return false;
  }
  char test_13 = 'x';
  bool output_13 = is_head(test_13);
  if (!assert_true("output_13", output_13)) {
    return false;
  }
  return true;
}

bool test_is_snake() {
  // TODO: Implement this function.
  char test_1 = 'W';
  bool output_1 = is_snake(test_1);
  if (!assert_true("output_1", output_1)) {
    return false;
  }
  char test_2 = 'A';
  bool output_2 = is_snake(test_2);
  if (!assert_true("output_2", output_2)) {
    return false;
  }
  char test_3 = 'S';
  bool output_3 = is_snake(test_3);
  if (!assert_true("output_3", output_3)) {
    return false;
  }

  char test_4 = 'D';
  bool output_4 = is_snake(test_4);
  if (!assert_true("output_4", output_4)) {
    return false;
  }

  char test_5 = 'w';
  bool output_5 = is_snake(test_5);
  if (!assert_true("output_5", output_5)) {
    return false;
  }
  char test_6 = 'a';
  bool output_6 = is_snake(test_6);
  if (!assert_true("output_6", output_6)) {
    return false;
  }
  char test_7 = 's';
  bool output_7 = is_snake(test_7);
  if (!assert_true("output_7", output_7)) {
    return false;
  }
  char test_8 = 'd';
  bool output_8 = is_snake(test_8);
  if (!assert_true("output_8", output_8)) {
    return false;
  }
  char test_9 = '^';
  bool output_9 = is_snake(test_9);
  if (!assert_true("output_9", output_9)) {
    return false;
  }
  char test_10 = '<';
  bool output_10 = is_snake(test_10);
  if (!assert_true("output_10", output_10)) {
    return false;
  }
  char test_11 = 'v';
  bool output_11 = is_snake(test_11);
  if (!assert_true("output_11", output_11)) {
    return false;
  }
  char test_12 = '>';
  bool output_12 = is_snake(test_12);
  if (!assert_true("output_12", output_12)) {
    return false;
  }
  char test_13 = 'x';
  bool output_13 = is_snake(test_13);
  if (!assert_true("output_13", output_13)) {
    return false;
  }
  return true;
}

bool test_body_to_tail() {
  // TODO: Implement this function.
  char test_1 = '^';
  char output_1 = body_to_tail(test_1);
  if (!assert_equals_char("output_1", 'w', output_1)) {
        return false;
  }
  char test_2 = '<';
  char output_2 = body_to_tail(test_2);
  if (!assert_equals_char("output_2", 'a', output_2)) {
        return false;
  }
  char test_3 = 'v';
  char output_3 = body_to_tail(test_3);
  if (!assert_equals_char("output_3", 's', output_3)) {
        return false;
  }
  char test_4 = '>';
  char output_4 = body_to_tail(test_4);
  if (!assert_equals_char("output_4", 'd', output_4)) {
        return false;
  }
  return true;
}

bool test_head_to_body() {
  // TODO: Implement this function.
  char test_1 = 'W';
  char output_1 = head_to_body(test_1);
  if (!assert_equals_char("output_1", '^', output_1)) {
        return false;
  }
  char test_2 = 'A';
  char output_2 = head_to_body(test_2);
  if (!assert_equals_char("output_2", '<', output_2)) {
        return false;
  }
  char test_3 = 'S';
  char output_3 = head_to_body(test_3);
  if (!assert_equals_char("output_3", 'v', output_3)) {
        return false;
  }
  char test_4 = 'D';
  char output_4 = head_to_body(test_4);
  if (!assert_equals_char("output_4", '>', output_4)) {
        return false;
  }
  return true;
}

bool test_get_next_row() {
  // TODO: Implement this function.
  char test_1 = 'W';
  unsigned int test_row_1 = 1;
  unsigned int output_1 = get_next_row(test_row_1, test_1);
  if (!assert_equals_unsigned_int("output_1", 0, output_1)) {
    return false;
  }
  char test_2 = 'A';
  unsigned int test_row_2 = 2;
  unsigned int output_2 = get_next_row(test_row_2, test_2);
  if (!assert_equals_unsigned_int("output_2", 2, output_2)) {
    return false;
  }

  char test_3 = 'S';
  unsigned int test_row_3 = 3;
  unsigned int output_3 = get_next_row(test_row_3, test_3);
  if (!assert_equals_unsigned_int("output_3", 4, output_3)) {
    return false;
  }

  char test_4 = 'D';
  unsigned int test_row_4 = 4;
  unsigned int output_4 = get_next_row(test_row_4, test_4);
  if (!assert_equals_unsigned_int("output_4", 4, output_4)) {
    return false;
  }

  char test_5 = 'w';
  unsigned int test_row_5 = 5;
  unsigned int output_5 = get_next_row(test_row_5, test_5);
  if (!assert_equals_unsigned_int("output_5", 4, output_5)) {
    return false;
  }

  char test_6 = 'a';
  unsigned int test_row_6 = 6;
  unsigned int output_6 = get_next_row(test_row_6, test_6);
  if (!assert_equals_unsigned_int("output_6", 6, output_6)) {
    return false;
  }

  char test_7 = 's';
  unsigned int test_row_7 = 7;
  unsigned int output_7 = get_next_row(test_row_7, test_7);
  if (!assert_equals_unsigned_int("output_1", 8, output_7)) {
    return false;
  }

  char test_8 = 'd';
  unsigned int test_row_8 = 8;
  unsigned int output_8 = get_next_row(test_row_8, test_8);
  if (!assert_equals_unsigned_int("output_8", 8, output_8)) {
    return false;
  }

  char test_9 = '^';
  unsigned int test_row_9 = 9;
  unsigned int output_9 = get_next_row(test_row_9, test_9);
  if (!assert_equals_unsigned_int("output_9", 8, output_9)) {
    return false;
  }

  char test_10 = '<';
  unsigned int test_row_10 = 10;
  unsigned int output_10 = get_next_row(test_row_10, test_10);
  if (!assert_equals_unsigned_int("output_10", 10, output_10)) {
    return false;
  }

  char test_11 = 'v';
  unsigned int test_row_11 = 11;
  unsigned int output_11 = get_next_row(test_row_11, test_11);
  if (!assert_equals_unsigned_int("output_11", 12, output_11)) {
    return false;
  }

  char test_12 = '>';
  unsigned int test_row_12 = 12;
  unsigned int output_12 = get_next_row(test_row_12, test_12);
  if (!assert_equals_unsigned_int("output_12", 12, output_12)) {
    return false;
  }

  char test_13 = 'x';
  unsigned int test_row_13 = 13;
  unsigned int output_13 = get_next_row(test_row_13, test_13);
  if (!assert_equals_unsigned_int("output_13", 13, output_13)) {
    return false;
  }
  return true;
}

bool test_get_next_col() {
  // TODO: Implement this function.
  char test_1 = 'W';
  unsigned int test_col_1 = 1;
  unsigned int output_1 = get_next_col(test_col_1, test_1);
  if (!assert_equals_unsigned_int("output_1", 1, output_1)) {
    return false;
  }
  char test_2 = 'A';
  unsigned int test_col_2 = 2;
  unsigned int output_2 = get_next_col(test_col_2, test_2);
  if (!assert_equals_unsigned_int("output_2", 1, output_2)) {
    return false;
  }

  char test_3 = 'S';
  unsigned int test_col_3 = 3;
  unsigned int output_3 = get_next_col(test_col_3, test_3);
  if (!assert_equals_unsigned_int("output_3", 3, output_3)) {
    return false;
  }

  char test_4 = 'D';
  unsigned int test_col_4 = 4;
  unsigned int output_4 = get_next_col(test_col_4, test_4);
  if (!assert_equals_unsigned_int("output_4", 5, output_4)) {
    return false;
  }

  char test_5 = 'w';
  unsigned int test_col_5 = 5;
  unsigned int output_5 = get_next_col(test_col_5, test_5);
  if (!assert_equals_unsigned_int("output_5", 5, output_5)) {
    return false;
  }

  char test_6 = 'a';
  unsigned int test_col_6 = 6;
  unsigned int output_6 = get_next_col(test_col_6, test_6);
  if (!assert_equals_unsigned_int("output_6", 5, output_6)) {
    return false;
  }

  char test_7 = 's';
  unsigned int test_col_7 = 7;
  unsigned int output_7 = get_next_col(test_col_7, test_7);
  if (!assert_equals_unsigned_int("output_1", 7, output_7)) {
    return false;
  }

  char test_8 = 'd';
  unsigned int test_col_8 = 8;
  unsigned int output_8 = get_next_col(test_col_8, test_8);
  if (!assert_equals_unsigned_int("output_8", 9, output_8)) {
    return false;
  }

  char test_9 = '^';
  unsigned int test_col_9 = 9;
  unsigned int output_9 = get_next_col(test_col_9, test_9);
  if (!assert_equals_unsigned_int("output_9", 9, output_9)) {
    return false;
  }

  char test_10 = '<';
  unsigned int test_col_10 = 10;
  unsigned int output_10 = get_next_col(test_col_10, test_10);
  if (!assert_equals_unsigned_int("output_10", 9, output_10)) {
    return false;
  }

  char test_11 = 'v';
  unsigned int test_col_11 = 11;
  unsigned int output_11 = get_next_col(test_col_11, test_11);
  if (!assert_equals_unsigned_int("output_11", 11, output_11)) {
    return false;
  }

  char test_12 = '>';
  unsigned int test_col_12 = 12;
  unsigned int output_12 = get_next_col(test_col_12, test_12);
  if (!assert_equals_unsigned_int("output_12", 13, output_12)) {
    return false;
  }

  char test_13 = 'x';
  unsigned int test_col_13 = 13;
  unsigned int output_13 = get_next_col(test_col_13, test_13);
  if (!assert_equals_unsigned_int("output_13", 13, output_13)) {
    return false;
  }

  return true;
}

bool test_customs() {
  if (!test_greater_than_forty_two()) {
    printf("%s\n", "test_greater_than_forty_two failed.");
    return false;
  }
  if (!test_is_vowel()) {
    printf("%s\n", "test_is_vowel failed.");
    return false;
  }
  if (!test_is_tail()) {
    printf("%s\n", "test_is_tail failed");
    return false;
  }
  if (!test_is_head()) {
    printf("%s\n", "test_is_head failed");
    return false;
  }
  if (!test_is_snake()) {
    printf("%s\n", "test_is_snake failed");
    return false;
  }
  if (!test_body_to_tail()) {
    printf("%s\n", "test_body_to_tail failed");
    return false;
  }
  if (!test_head_to_body()) {
    printf("%s\n", "test_head_to_body failed");
    return false;
  }
  if (!test_get_next_row()) {
    printf("%s\n", "test_get_next_row failed");
    return false;
  }
  if (!test_get_next_col()) {
    printf("%s\n", "test_get_next_col failed");
    return false;
  }
  return true;
}

int main(int argc, char* argv[]) {
  init_colors();

  if (!test_and_print("custom", test_customs)) {
    return 0;
  }

  return 0;
}
