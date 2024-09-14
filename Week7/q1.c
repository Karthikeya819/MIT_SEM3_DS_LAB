/*
Implement a circular queue of Strings using structures. Include functions insertcq, deletecq and displaycq.
*/

#include <stdio.h>
#include <string.h>
#define Max_Size 20

typedef struct{
    char Items[Max_Size][20];
    int front;
    int rear;
}Queue;

void Initialize_Queue(Queue *q){
    q->front = -1;
    q->rear = -1;
}
int is_Full(Queue *q){
    if((q->rear+1)%Max_Size == q->front){
        return 1;
    }
    return 0;
}
int is_Empty(Queue *q){
    if(q->rear == -1){
        return 1;
    }
    return 0;
}
void insertcq(Queue *q,char *item){
    if(is_Full(q)){
        printf("Queue is Full!");
        return;
    }
    if(is_Empty(q)){
        strcpy(q->Items[0],item);
        q->rear = 0;
        q->front =0;
        return;
    }
    q->rear = (q->rear+1) % Max_Size;
    strcpy(q->Items[q->rear],item);
}

void deletecq(Queue *q,char *output){
    if(is_Empty(q)){
        printf("Queue is Empty!");
    }
    strcpy(output,q->Items[q->front]);
    if(q->front == q->rear){
        q->front = -1;
        q->rear = -1;
    }else{
        q->front = (q->front + 1) % Max_Size;
    }
}

void displaycq(Queue *q){
    if(is_Empty(q)){
        printf("Queue is Empty! \n");
        return;
    }
    int i = q->front;
    while (1) {
        printf("%s ", q->Items[i]);
        if (i == q->rear) {
            break;
        }
        i = (i + 1) % Max_Size;
    }
    printf("\n");
}

int main(){
    Queue que;
    Initialize_Queue(&que);
    insertcq(&que,"item1");
    insertcq(&que,"item2");
    insertcq(&que,"item3");
    insertcq(&que,"item4");
    insertcq(&que,"item5");
    char Output[30];
    deletecq(&que,&Output[0]);
    printf("EnQueued Element: %s \n",Output);
    displaycq(&que);

    return 0;
}