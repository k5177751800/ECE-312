/* mathStuff_ks54897.c

Programmer: Konghwan Shin
EE312  <Jull 11, 2023>

Finish comments here
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//**********  Function Prototypes  ******************

//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//

bool isPrime (int number);



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.

void printPrimes (int n);


//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0
//Fib(1) -> 1
//Fib(N) -> Fib(N-2) + Fib(N-1)

int findFibo (int n);


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime

void findFactors (int number);



//******************  MAIN  *****************************

int main () {
    int testNum;

    //test for the isPrime function
    printf("Enter a test number - ");
    scanf("%d",&testNum);

    if (isPrime(testNum))
        printf("%d is prime\n",testNum);
    else
        printf("%d is not prime.", testNum);

    //test for printing primes
    printf("Enter n to print the prime numbers between 1 and n: ");
    scanf("%d",&testNum);

    if (testNum<0){
        printf("Warning, Input a positive integer");
    } else{
        printPrimes(testNum);
    }


    printf("\n");

    //test for Fibonacci number finder
    printf("Which Fibonacci number? ");
    scanf("%d",&testNum);

    if (testNum<0){
        printf("Warning, Input a positive integer");
    } else{
        printf("The %d Fibonacci number is : %d \n", testNum, findFibo(testNum));
    }

    printf("\n");

    //test for prime factors
    printf("Factor what number? ");
    scanf("%d",&testNum);

    if (testNum<0){
        printf("Warning, Input a positive integer");
    } else{
        findFactors(testNum);
    }



    return 0;

}




//function isPrime
//input parameter - positive integer
//returns true if the number is prime, otherwise false
//



//function printPrimes
//input parameter - positive integer
//Uses the isPrime method to print a list of prime numbers between 1 and n.


bool isPrimeH(int number, int START_DIVISOR){
    //HINT: You may want a helper function
    if (number <= 2)
        return (number == 2);
    if (number % START_DIVISOR == 0)
        return false;
    if (START_DIVISOR * START_DIVISOR > number)
        return true;
    return isPrimeH(number, START_DIVISOR + 1);
}

bool isPrime (int number) {
    return isPrimeH(number, 2);
    //HINT: You may want a helper function

    //YOUR CODE GOES HERE

}

void printPrimesH(int n, int c){
    if (c > n)
        return;
    if (isPrime(c))
        printf("%d\n", c);
    printPrimesH(n, c + 1);

}

void printPrimes (int n) {

    //YOUR CODE GOES HERE
    printPrimesH(n, 2);

}



//function findFibo
//input parameter - positive integer
//returns the nth fibonacci number where
//Fib(0) -> 0 
//Fib(1) -> 1 
//Fib(N) -> Fib(N-2) + Fib(N-1)
int findFiboH (int n) {

    //YOUR CODE GOES HERE
    if (n == 0){
        return 0;
    }

    if (n == 1){
        return 1;
    }

    return findFiboH(n - 1) + findFiboH(n - 2);
}

int findFibo(int n){
    return findFiboH(n);
}


//function findFactors
//input parameter - positive integer
//prints the prime factors of the given number to standard output (cout)
//example output: 52=2*2*13 (or 52=1*2*2*13) or 13=prime
void findFactorsH(int number, int START_DIVISOR) {
    if (number == 1){
        return;
    }
    if (number % START_DIVISOR == 0) {
        printf("%d", START_DIVISOR);
        if (number != START_DIVISOR){
            printf("*");
        }
        findFactorsH(number / START_DIVISOR, START_DIVISOR);
    } else {
        findFactorsH(number, START_DIVISOR + 1);
    }
}


void findFactors(int number) {
    printf("%d=", number);
    if (isPrime(number)) {
        printf("prime");
        return;
    }
    findFactorsH(number, 2);
    printf("\n");
}



