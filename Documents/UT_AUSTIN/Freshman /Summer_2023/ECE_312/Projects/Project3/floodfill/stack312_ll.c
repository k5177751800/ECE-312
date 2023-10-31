//Konghwan Shin
//ECE 312, project 3
//KS54897
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stack312_ll.h"

void makeStack(Stack312 *sp) {
    sp->top = NULL;
};

bool isFull(Stack312 s){
    StackNode* nNode = (StackNode*)malloc(sizeof(StackNode));
    if (nNode == NULL) {
        return false;
    }
    else {
        free(nNode);
        return true;
    }

};

bool isEmpty(Stack312 s){
    return (s.top == NULL);
};

void push(StackEntry e,Stack312 *sp){


    StackNode* stackNode = (StackNode*)malloc(sizeof(StackNode));
    if (stackNode != NULL){
        stackNode->pixel = e;
        stackNode->next = sp->top;
        sp->top = stackNode; // point root to new top node

    }
};

StackEntry pop(Stack312 *sp) {
    if(isEmpty(*sp)){
        StackEntry null;
        return null;
    }
    StackNode* tmpN = sp -> top;
    sp -> top = tmpN -> next;
    StackEntry pop = tmpN -> pixel;
    free(tmpN);
    return pop;
}
