#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<stdint.h>




// CodeCamp.c -- EE 312 Project 1

/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <Konghwan Shin>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Konghwan Shin
 * email address: kshin1@utexas.edu
 * UTEID: ks54897
 * Section 5 digit ID:75590
 *
 */



/* Determine the hamming distance between two int arrays.
   pre: aList != null, bList != null, aList.length == bList.length == len
   post: return hamming distance between the two arrays of ints.
   Neither parameter should be altered by this function.
*/

int hammingDistance(int aList[], int bList[], int len) {
  // EE 312 Students: put your code here
  int i;
  int res = 0;
    for (int i = 0; i < len; i++) {
        if (aList[i] != bList[i]){
            res ++;
        }
    }
    return res;
}


/* Determine if two ints have the same last digit.
   Note that the last digit of 0 is 0 and the last digit of -12 is 2.
   post: return true if num1 and num2 have the same last digit, false otherwise.
*/

bool lastDigit(int num1, int num2) {
 
  // EE 312 Students: put your code here
  if(num1 % 10 == num2 % 10 ) {       /*Checking the last digit of the int input when both int is positive or neg*/
      return true;
  }
  else if (num1<0){                   /*when one int is neg*/
      num1  = (num1 *-1) % 10;
      if(num1 == num2 % 10){
          return true;
      }
  }
  else if(num2<0){
      num2 = (num2*-1) % 10;
      if(num1 %10 == num2){
          return true;
      }
  }
  else{
      return false;
  }
}

/* Determine the sum of the positive integers less than 1000 that are multiples of 3 or 5 (or both).
   post: return the sum of the integers from 1 to 1000 that are multiples of 3 or 5 or both.
*/

int sum3or5Multiples() {
    int count = 0;
  // EE 312 Students: put your code here
    for (int i = 0; i < 1000; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            count = count + i;
        }
    }
    return count;
}

/* Reverse the digits of an integer. Return the reversed number if it is in the range of type int, 0 otherwise.
   post: return num with digits reversed if the reverse can be stored as an int, 0 otherwise.
*/

int reverseInt(int num) {

  // EE 312 Students: put your code here
    const int intRange = 2147483648;
    int64_t res = 0;
    while(num > 0 || num < 0){
        res = res * 10;
        res = res + num % 10;
        num = num - num % 10;
        num = num / 10;

    }
    if(res > intRange - 1 || res < -intRange ){
        return 0;
    }

    return res;

}

  


