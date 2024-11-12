// Circular Queue

#include <stdio.h>
#include <stdlib.h>
#define Queue_Max_Size 4

typedef struct{
    int Arr[Queue_Max_Size],front,rear;
}Queue;

int Is_Full(Queue *que){
    return (que->rear + 1)%Queue_Max_Size == que->front;
}

int Is_Empty(Queue *que){
    return que->rear == -1;
}

void insertcq(Queue *que,int item){
    if(Is_Full(que)){
        printf("Failed to Insert! Queue is Full");
        return;
    }
    if(Is_Empty(que)){
        que->rear = 0;que->front = 0;
        que->Arr[0] = item;
        return;
    }
    que->rear = (que->rear+1)%Queue_Max_Size;
    que->Arr[que->rear] = item;
}

int deletecq(Queue *que){
    if(Is_Empty(que)){
        printf("Delete Failed! Queue is Empty");
        exit(0);
    }
    int ret = que->Arr[que->front];
    if(que->front == que->rear){
        que->front = -1;que->rear = -1;
        return ret;
    }
    que->front = (que->front + 1) % Queue_Max_Size;
    return ret;
}

int main(){
    Queue que;
    que.rear = -1;que.front = -1;
    insertcq(&que,1);
    insertcq(&que,2);
    insertcq(&que,3);
    insertcq(&que,4);
    insertcq(&que,1);
    insertcq(&que,2);

    printf("%d",deletecq(&que));
    insertcq(&que,1);
    printf("%d",deletecq(&que));

    printf("%d",deletecq(&que));


    return 0;
}