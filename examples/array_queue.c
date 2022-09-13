/*
 * 
 * Author: Aaryan D.
 *
 * Demonstrate a queue implemented as a array.
 * 
 */


#include<stdio.h>

#define MAX_INDEX 100



int head = 0,tail = -1;
int queue[MAX_INDEX + 1];

int isEmpty(void){
    
    if(head > tail){
        return 1;
    }

    return 0;
}

int isFull(void){
    
    if (tail == MAX_INDEX - 1){
        return 1;
    }

    return 0;
}

void enqueue(int data){
    if(isFull() == 1){
        printf("\nWARN: enqueue: queue is full\n");
        return;
    }

    queue[++tail] = data; 

    return;
}

int dequeue(void){
    if(isEmpty() == 1){
        printf("\nWARN: dequeue: attempt to read from empty queue\n");
        return 0;
    }

    return queue[head++];
}

int front(void){
    return queue[head];  
}

int rear(void){
    return queue[tail];
}

int size(void){
    return tail-head+1;
}

/*

this is a test function!

it takes 3 user inputs, adds them to the queue and then removes them from the stack. its that simple. Feel free to use the above methods as you like :D

*/

void main(){
    int inp1 = 0, inp2 = 0, inp3 = 0;
    int op1,op2,op3,op4;
    scanf("%d,%d,%d",&inp1,&inp2,&inp3);

    enqueue(inp1);
    enqueue(inp2);
    enqueue(inp3);

    op1 = dequeue();
    op2 = dequeue();
    op3 = dequeue();   

    //Test warning if the queue is empty
    op4 = dequeue(); //will print warning and be 0

    

    printf("\n%d,%d,%d,%d", op1, op2, op3, op4);

}