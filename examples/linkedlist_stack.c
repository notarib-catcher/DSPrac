/*
 * 
 * Author: Aaryan D.
 *
 * Demonstrate a stack implemented as a linked list.
 * 
 */


#include<stdio.h>
#include<stdlib.h>

struct stack_elem {
    int data;
    void* next_elem;
};

typedef struct stack_elem STKMEMBR;

struct stack_metadata {
    STKMEMBR* top_elem;
};

typedef struct stack_metadata STKDAT;


// Your usual stack manipulation functions: push and pop


void push(STKDAT* _stkdat, int _dat){

    STKMEMBR* newmem = (STKMEMBR*) malloc(sizeof(STKMEMBR));
    newmem -> data = _dat;
    newmem -> next_elem = (void*) _stkdat -> top_elem;
    _stkdat -> top_elem = newmem;

}

int pop(STKDAT* _stkdat){

    if((_stkdat -> top_elem) == NULL){
        return 0;
    }

    int _ret = (_stkdat -> top_elem) -> data;
    void* _tofree = (void*) _stkdat -> top_elem;
    _stkdat -> top_elem = (STKMEMBR*) (_stkdat -> top_elem) -> next_elem;
    free(_tofree);

    return _ret;

}

STKDAT make_new_stack(){

    STKDAT _ret;
    _ret.top_elem = NULL;

    return _ret;

}

/*

this is a test function!

it takes 3 user inputs, adds them to the stack and then removes them from the stack. its that simple. Feel free to use the above methods as you like :D

*/

void main(){

    int inp1 = 0, inp2 = 0, inp3 = 0;
    int op1,op2,op3,op4;
    scanf("%d,%d,%d",&inp1,&inp2,&inp3);

    STKDAT s1 = make_new_stack();
    push(&s1,inp1);
    push(&s1,inp2);
    push(&s1,inp3);

    op1 = pop(&s1);
    op2 = pop(&s1);
    op3 = pop(&s1);   

    //Test that it doesn't bug out if the queue is empty
    op4 = pop(&s1); //will be zero

    

    printf("\n%d,%d,%d,%d", op1, op2, op3, op4);
}