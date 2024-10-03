#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

typedef struct{
    int Arr[Max_Size];
    int front,rear;
}Queue;

void Init_Queue(Queue *q){
    q-> front = -1;
    q->rear = -1;
}
int is_Full(Queue *q){
    return q->rear == Max_Size-1;
}
int is_Empty(Queue *q){
    return q->front == -1;
}

void enqueue(Queue *q,int item){
    if(is_Full(q)){
        printf("Queue is Full!");
        return;
    }
    if(is_Empty(q)){
        q->Arr[++(q->rear)] = item;
        q->front = 0;
        return;
    }
    q->Arr[++(q->rear)] = item;
}

int dequeue(Queue *q){
    if(is_Empty(q)){
        printf("Queue is Empty!");
        exit(0);
    }
    if(q->front == q->rear){
        int temp = q->Arr[(q->front)++];
        q->front = -1;
        q->rear = -1;
        return temp;
    }
    return q->Arr[(q->front)++];
}

void Reverse_Queue(Queue *q){
    if(is_Empty(q))return;
    int temp = dequeue(q);
    Reverse_Queue(q);
    enqueue(q,temp);
}

int main(){
    Queue que;
    Init_Queue(&que);
    enqueue(&que,1);
    enqueue(&que,2);
    enqueue(&que,3);
    Reverse_Queue(&que);
    printf("Reversed Queue:");
    printf("%d ",dequeue(&que));
    printf("%d ",dequeue(&que));
    printf("%d ",dequeue(&que));
    
    return 0;
}