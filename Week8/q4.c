/*
4)	Given a queue of integers, write a program to reverse the queue, using only the following operations:
i.	 enqueue(x): Add an item x to rear of queue.
ii.	 dequeue() : Remove an item from front of queue.
iii. empty() : Checks if a queue is empty or not.
*/

#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

typedef struct{
    int Arr[Max_Size];
    int front,rear;
}Queue;

void Init_Queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}
int is_Empty(Queue *q){
    return q->front == -1;
}
int is_Full(Queue *q){
    return q->rear == Max_Size - 1;
}
void enqueue(Queue *q,int item){
    if(is_Full(q)){
        printf("Queue is Full!");
    }
    if(is_Empty(q)){
        q->front = 0;
    }
    q->Arr[++q->rear] = item;
}
int dequeue(Queue *q){
    if(is_Empty(q)){
        printf("Queue is Empty!");
        exit(0);
    }
    int temp = q->Arr[q->front++];
    if(q->rear+1 == q->front){
        q->front = -1;
        q->rear = -1;
    }
    return temp;
}

void Reverse_Queue(Queue *q){
    if(is_Empty(q))return;
    int temp = dequeue(q);
    Reverse_Queue(q);
    enqueue(q,temp);
}

int main(){
    printf("Hello WOrld! \n");
    Queue que;
    Init_Queue(&que);
    enqueue(&que,1);
    enqueue(&que,2);
    enqueue(&que,3);
    Reverse_Queue(&que);
    printf("%d \n",dequeue(&que));
    return 0;
}