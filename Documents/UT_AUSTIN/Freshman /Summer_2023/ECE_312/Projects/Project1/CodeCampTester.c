#include<stdio.h>
#include<stdbool.h>


// CodeCampTester.c -- EE 312 Project 1 -- Tester class

/* Student information for assignment:
 * 
 * Name: Konghwan Shin
 * email address: kshin1@utexas.edu
 * UTEID: ks54897
 * Section 5 digit ID: 75590
 *  
 */

//function prototypes. These will be completed in CodeCamp.c
int hammingDistance(int aList[], int bList[], int len);
int sum3or5Multiples();
bool lastDigit(int num1, int num2);
int reverseInt(int num); 
//****************************

int main() {
  
  // test 1, hammingDistance
  int h1[] = {2, 1, 10, 5, 5, 12, 2, 2, 1};
  int h2[] = {3, 1, 10, 4, 5, 12, 3, -9, 1};
  int expected = 4;
  int actual = hammingDistance(h1, h2, 9);
  printf("Test 1 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 1, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 1, hamming distance\n\n");

  // test 2, hamming distance
  int h3[] = {1, 4, 1, 2, 5, 6, 7, 8, 9, 10};
  int h4[] = {1, -7, -3, -5, -5, -5, -5, -5, -5, -5};
  expected = 9;
  actual = hammingDistance(h3, h4, 10);
  printf("Test 2 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 2, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 2, hamming distance\n\n");

  // test 3, hamming distance
  int h5[30000] = {1};
  int h6[30000] = {0};
  expected = 1;
  actual = hammingDistance(h5, h6, 30000);
  printf("Test 3 hamming distance: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 3, hamming distance\n\n");
  else 
     printf("**** FAILED **** test 3, hamming distance\n\n");

  // test 4, last digit
  int n1 = 1000;
  int n2 = 450;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 4, last digit\n\n");
  else 
     printf("**** FAILED **** test 4, last digit\n\n");

  // test 5, last digit
  n1 = -24564;
  n2 = 1534;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 4 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
    printf("passed test 5, last digit\n\n");
  else 
     printf("**** FAILED **** test 5, last digit\n\n");

  // test 6, last digit
  n1 = 1245;
  n2 = 3115;
  expected = true;
  actual = lastDigit(n1, n2);
  printf("Test 6 last digit: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)   
    printf("passed test 6, last digit\n\n");
  else 
     printf("**** FAILED **** test 6, last digit\n\n");

  // test 7, sum of multiples of 3 or 5
  expected = 233168;
  actual = sum3or5Multiples();
  printf("Test 7 sum of multiples: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 7, sum of multiples of 3 or 5\n\n");
  else 
     printf("**** FAILED **** test 7, sum of multiples of 3 or 5\n\n");

  // test 8, reverse int
  n1 = -234;
  expected = -432;
  actual = reverseInt(n1);
  printf("Test 8 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 8, reverse int\n\n");
  else 
     printf("**** FAILED **** test 8, reverse int\n\n");

  // test 9, reverse int
  n1 = 300;
  expected = 3;
  actual = reverseInt(n1); 
  printf("Test 9 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 9, reverse int\n\n");
  else 
     printf("**** FAILED **** test 9, reverse int\n\n");

  // test 10, reverse int
  n1 = 2001;
  expected = 1002;
  actual = reverseInt(n1); 
  printf("Test 10 reverse int: expected value: %d, actual value: %d\n", expected, actual);

  if(expected == actual)  
     printf("passed test 10, reverse int\n");
  else 
     printf("**** FAILED **** test 10, reverse int\n");

}

