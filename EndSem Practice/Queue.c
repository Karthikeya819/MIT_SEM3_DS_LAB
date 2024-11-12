// Linear Queue
#include <stdio.h>
#include <stdlib.h>
#define Queue_Max_Size 20

typedef struct{
    int Arr[Queue_Max_Size],rear,front;
}Queue;

int Is_Full(Queue *que){
    return que->rear == Queue_Max_Size - 1;
}
int Is_Empty(Queue *que){
    return que->front == -1;
}

void insertq(Queue *que,int item){
    if(Is_Full(que)){
        printf("Queue is Full! \n");
        return;
    }
    que->Arr[++(que->rear)] = item;
    if(Is_Empty(que))que->front = 0;
}
int deleteq(Queue *que){
    if(Is_Empty(que)){
        printf("Queue is Empty! \n");
        exit(0);
    }
    if(que->front == que->rear){
        int ret = que->Arr[(que->front)++];
        que->rear = -1;
        que->front = -1;
        return ret;
    }
    return que->Arr[(que->front)++];
}

void displayq(Queue *que){
    if(Is_Empty(que))printf("Queue is Empty!");
    for(int i = que->front;i<=que->rear;i++)printf("%d ",que->Arr[i]);
}

int main(){
    Queue que;que.rear = -1;que.front = -1;
    insertq(&que,2);insertq(&que,3);
    displayq(&que);
    printf("%d",deleteq(&que));
    printf("%d",deleteq(&que));
    //printf("%d",deleteq(&que));
    return 0;
}