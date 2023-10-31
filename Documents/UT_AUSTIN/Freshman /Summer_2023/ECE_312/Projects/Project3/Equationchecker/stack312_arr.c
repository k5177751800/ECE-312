//Konghwan Shin
//ECE 312
//KS54897
#include "stack312_arr.h"
#include <stdio.h>
#include <stdbool.h>


void makeStack(Stack312 *sp){
    sp ->top = -1;
};
//Checking if it is full
bool isFull(Stack312 s){
    return s.top == MAX_ELEMENTS - 1;
};

//If stack is empty return -1
bool isEmpty(Stack312 s){
    return s.top == -1;
};

//pushing to stack
void push(StackEntry e,Stack312 *sp){
    if (isFull(*sp)== false){
        sp-> top++;
        sp->elements[sp->top] = e;
    }
};

StackEntry pop(Stack312 *sp){
    if (isEmpty(*sp)) {
        return '\0';
    } else {
        StackEntry pop = sp->elements[sp->top];
        sp->top--;
        return pop;
    }
};