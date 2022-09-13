/*
 * 
 * Author: Aaryan D.
 *
 * Demonstrate a stack implemented as an array.
 * 
 */


#include <stdio.h>

#define MAXSTACKSIZE 100

int stk[MAXSTACKSIZE];
int stk_top = -1;

// Checks for empty and full stack -> This is a stack of fized size and needs both of these

int isEmpty(){
    
    if (stk_top == -1){
        return 1;
    }

    return 0;
    
}

int isFull(){

    if(stk_top == MAXSTACKSIZE-1){
        return 1;
    }

    return 0;
}

// Your usual stack manipulation/access functions: push, pop and peek

void push(int data){
    
    if(isFull() == 1){
        return;
    }

    stk[++stk_top] = data;

}

int pop(){

    if(isEmpty() == 1){
        return 0;
    }

    stk_top--;
    return stk[stk_top+1];
}

int peek(){

    if (isEmpty() == 1){
        return 0;
    }
    
    return stk[stk_top];
}

/*

this is a test function!

it takes 3 user inputs, adds them to the stack and then removes them from the stack. its that simple. Feel free to use the above functions as you like :D

*/

void main(){
    int inp1 = 0, inp2 = 0, inp3 = 0;
    int op1,op2,op3,op4;
    scanf("%d,%d,%d",&inp1,&inp2,&inp3);

    push(inp1);
    push(inp2);
    push(inp3);

    op1 = pop();
    op2 = pop();
    op3 = pop();   

    //Test that it doesn't bug out if the stack is empty
    op4 = pop(); //will be zero

    

    printf("\n%d,%d,%d,%d", op1, op2, op3, op4);

}