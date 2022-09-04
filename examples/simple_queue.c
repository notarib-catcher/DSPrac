/*
 * 
 * Author: Aaryan D.
 *
 * Demonstrate a simple queue in C using a linked list.
 * 
 */


#include<stdio.h>
#include<stdlib.h>

struct queue_member {
    int data;
    void *next_member;
};

typedef struct queue_member QMEMBER;

struct queue_data{
    QMEMBER* head;
    QMEMBER* tail;
};

typedef struct queue_data QDAT;

int get_next_data(QDAT *_cq){

    if(_cq->head == NULL || _cq->tail == NULL){ //if no data in queue
        return 0;
    }

    int _ret = (_cq->head)->data; //get the data and store it in a returnable var
    void* _tofree = (_cq->head); //store the location of the current head element


    if(((QMEMBER*)(_cq->head))->next_member == NULL){
        _cq->head = NULL;
        _cq->tail = NULL;
        free(_tofree);
        return _ret;
    }

    _cq->head = (QMEMBER*) (_cq->head)->next_member;  //update the head element to the next one
    free(_tofree);  //free the head data
    return _ret; 
}




void add_new_member(QDAT *_cq, int _data){


    //create new element

    QMEMBER* new_elem = (QMEMBER*) malloc(sizeof(QMEMBER));
    new_elem->data = _data;
    new_elem->next_member = NULL;
    
    if(_cq->head == NULL || _cq->tail == NULL){
        _cq->head = new_elem;
        _cq->tail = new_elem;
        return;
    }

    
    (_cq->tail)->next_member = (void*) new_elem;
    _cq->tail = new_elem;
    return;
}

QDAT make_new_queue(){
    QDAT _q;
    _q.head = NULL;
    _q.tail = NULL;
    return _q;
}



/* 

this is a test function!

it takes 3 user inputs, adds them to the queue and then removes them from the queue. its that simple. Feel free to use the above methods as you like :D

*/



void main(){

    int inp1 = 0, inp2 = 0, inp3 = 0;
    int op1,op2,op3,op4;
    scanf("%d,%d,%d",&inp1,&inp2,&inp3);

    QDAT q1 = make_new_queue();
    add_new_member(&q1,inp1);
    add_new_member(&q1,inp2);
    add_new_member(&q1,inp3);

    op1 = get_next_data(&q1);
    op2 = get_next_data(&q1);
    op3 = get_next_data(&q1);   

    //Test that it doesn't bug out if the queue is empty
    op4 = get_next_data(&q1); //will be zero

    

    printf("\n%d,%d,%d,%d", op1, op2, op3, op4);

}