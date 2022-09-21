/*
 * 
 * Author: Aaryan D.
 *
 * Demonstrate a circular queue implemented as an array.
 * 
 */

#include<stdio.h>
#include<windows.h>

#define MAXSIZE 10


int head = 0, tail = -1, q_size = 0;
int queue[MAXSIZE];


void nrmCLR(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
}
void redCLR(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 12);
}
void blueCLR(){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 11);
}

void enqueue(int data){
    if (q_size >= MAXSIZE){
        redCLR();
        printf("\nWARN: Could not insert value \'%d\', queue full.\n",data);
        nrmCLR();
        return;
    }

    q_size++;
    tail = (tail+1)%MAXSIZE;
    queue[tail] = data;
    return;
}

int dequeue(){
    if(q_size == 0){
        redCLR();
        printf("\nWARN: Attempt to dequeue from empty queue.\n");
        nrmCLR();
        return 0;
    }

    int _ret = queue[head];
    head = (head+1)%MAXSIZE;
    q_size--;
    return _ret;
}

void display(){
    if(q_size == 0){
        redCLR();
        printf("\nWARN: Cannot display an empty queue.");
        nrmCLR();
        return;
    }
    int i = 0, j = head;
    for(i = 0; i < q_size; i++){
        printf("\nElement: %d\n",queue[j]);
        j = (j+1)%MAXSIZE;
    }
}

int front(){
    if(q_size == 0){
        redCLR();
        printf("\nWARN: Cannot read front of empty queue.\n");
        nrmCLR();
        return 0;
    }

    return queue[head];
}

int rear(){
    if(q_size == 0){
        redCLR();
        printf("\nWARN: Cannot read rear of empty queue.\n");
        nrmCLR();
        return 0;
    }

    return queue[tail];
}

/*

this is a test function!

it takes user inputs, adds them to the queue and then removes them from the queue. its that simple. Feel free to use the above functions as you like :D

*/


void main(){
    int optn,num;
    while(1){
        printf("\n\nOptions:\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Front\n5.Rear\n6.Size\n7.Exit\n\nYour choice: ");
        scanf("%d",&optn);
        switch(optn){
            case 1: printf("\nEnter num to enqueue: ");
                    scanf("%d",&num);
                    enqueue(num);
                    blueCLR();
                    printf((q_size == MAXSIZE)?"":"Done!" );
                    nrmCLR();
                    break;

            case 2: if(q_size != 0){
                        blueCLR();
                    }
                    printf("\nDequeued: %d",dequeue());
                    nrmCLR();
                    break;

            case 3: blueCLR();
                    display();
                    nrmCLR();
                    break;

            case 4: blueCLR();
                    printf("\nFront value: %d",front());
                    nrmCLR();
                    break;

            case 5: blueCLR();
                    printf("\nRear value: %d", rear());
                    nrmCLR();
                    break;

            case 6: blueCLR();
                    printf("\nCurrent size: %d", q_size);
                    nrmCLR();
                    break;

            case 7: break;

            default: redCLR();
                     printf("\nInvalid choice!\n");
                     nrmCLR();
                     optn = 0;
                     continue;
        }

        if(optn == 7){
            break;
        }
    }

}
