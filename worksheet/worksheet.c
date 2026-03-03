/*
 * Week 6 Worksheet - Functions Practice
 *
 * This worksheet tests your understanding of:
 * - Pass by value (returning results)
 * - Pass by reference (modifying via pointers)
 * - Arrays as function arguments
 * - Output parameters
 */

#include "acutest.h"

/* ============================================================
 * FUNCTION PROTOTYPES - Do not modify these
 * ============================================================ */

int add_values(int a, int b);
void swap_values(int *a, int *b);
int sum_array(int *arr, int n);
void reverse_array(int *arr, int n);
double average(int *arr, int n);
int find_max(int *arr, int n, int *index);

/* ============================================================
 * STUDENT IMPLEMENTATIONS
 * ============================================================ */

int add_values(int a, int b) {
  return a + b;
}

void swap_values(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int sum_array(int *arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return sum;
}

void reverse_array(int *arr, int n) {
  for (int i = 0; i < n / 2; i++) {
    int temp = arr[i];
    arr[i] = arr[n - 1 - i];
    arr[n - 1 - i] = temp;
  }
}

double average(int *arr, int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  return (double)sum / n;
}

int find_max(int *arr, int n, int *index) {
  int max = arr[0];
  *index = 0;

  for (int i = 1; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
      *index = i;
    }
  }

  return max;
}

/* ============================================================
 * UNIT TESTS - Using Acutest framework
 * ============================================================ */

void test_add_values(void) {
  TEST_CHECK(add_values(3, 4) == 7);
  TEST_MSG("Expected add_values(3, 4) = 7");

  TEST_CHECK(add_values(0, 0) == 0);
  TEST_MSG("Expected add_values(0, 0) = 0");

  TEST_CHECK(add_values(-5, 5) == 0);
  TEST_MSG("Expected add_values(-5, 5) = 0");

  TEST_CHECK(add_values(-3, -7) == -10);
  TEST_MSG("Expected add_values(-3, -7) = -10");
}

void test_swap_values(void) {
  int a, b;

  a = 5;
  b = 10;
  swap_values(&a, &b);
  TEST_CHECK(a == 10 && b == 5);

  a = -1;
  b = 1;
  swap_values(&a, &b);
  TEST_CHECK(a == 1 && b == -1);

  a = 0;
  b = 100;
  swap_values(&a, &b);
  TEST_CHECK(a == 100 && b == 0);
}

void test_sum_array(void) {
  int arr1[] = {1, 2, 3, 4, 5};
  TEST_CHECK(sum_array(arr1, 5) == 15);

  int arr2[] = {10};
  TEST_CHECK(sum_array(arr2, 1) == 10);

  int arr3[] = {-1, -2, -3};
  TEST_CHECK(sum_array(arr3, 3) == -6);

  int arr4[] = {0, 0, 0, 0};
  TEST_CHECK(sum_array(arr4, 4) == 0);
}

void test_reverse_array(void) {
  int arr1[] = {1, 2, 3, 4, 5};
  int exp1[] = {5, 4, 3, 2, 1};
  reverse_array(arr1, 5);
  int ok = 1;
  for (int i = 0; i < 5; ++i) {
    if (arr1[i] != exp1[i])
      ok = 0;
  }
  TEST_CHECK(ok);

  int arr2[] = {1, 2};
  reverse_array(arr2, 2);
  TEST_CHECK(arr2[0] == 2 && arr2[1] == 1);

  int arr3[] = {42};
  reverse_array(arr3, 1);
  TEST_CHECK(arr3[0] == 42);
}

void test_average(void) {
  int arr1[] = {1, 2, 3, 4, 5};
  double avg1 = average(arr1, 5);
  TEST_CHECK(avg1 >= 2.99 && avg1 <= 3.01);

  int arr2[] = {1, 2};
  double avg2 = average(arr2, 2);
  TEST_CHECK(avg2 >= 1.49 && avg2 <= 1.51);

  int arr3[] = {10, 20, 30};
  double avg3 = average(arr3, 3);
  TEST_CHECK(avg3 >= 19.99 && avg3 <= 20.01);
}

void test_find_max(void) {
  int arr1[] = {3, 7, 2, 9, 4};
  int idx1;
  int max1 = find_max(arr1, 5, &idx1);
  TEST_CHECK(max1 == 9 && idx1 == 3);

  int arr2[] = {100};
  int idx2;
  int max2 = find_max(arr2, 1, &idx2);
  TEST_CHECK(max2 == 100 && idx2 == 0);

  int arr3[] = {-5, -2, -8, -1};
  int idx3;
  int max3 = find_max(arr3, 4, &idx3);
  TEST_CHECK(max3 == -1 && idx3 == 3);
}

TEST_LIST = {
    {"add_values", test_add_values},
    {"swap_values", test_swap_values},
    {"sum_array", test_sum_array},
    {"reverse_array", test_reverse_array},
    {"average", test_average},
    {"find_max", test_find_max},
    {NULL, NULL}};