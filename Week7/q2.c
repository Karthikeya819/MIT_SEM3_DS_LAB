/*
Implement two circular queues of integers in a single array where first queue will run from 0 to N/2 and 
second queue will run from N/2+1 to N-1 where N is the size of the array.
*/

#include <stdio.h>
#define Max_Size 8
#define Half_Size 4

typedef struct{
    int Items[Max_Size];
    int front1;
    int rear1;
    int front2;
    int rear2;
}Queue;

void Initialize_Queue(Queue *q){
    q->front1 = -1;
    q->rear1 = -1;
    q->front2 = Half_Size - 1;
    q->rear2 = Half_Size - 1;
}

int is_Full(int dir,Queue *q){
    if(!dir){
        if((q->rear1+1) % Half_Size == q->front1)return 1;
        return 0;
    }else{
        if(Half_Size+((q->rear2+1) % Half_Size) == q->front2)return 1;
        return 0;
    }
}

int is_Empty(int dir,Queue *q){
    if(!dir){
        if(q->rear1 == -1)return 1;
        return 0;
    }else{
        if(q->rear2 == (Half_Size-1))return 1;
        return 0;
    }
}
void insertcq(int dir,Queue *q,int item){
    if(is_Full(dir,q)){
        printf("Queue is Full!");
        return;
    }
    if(is_Empty(dir,q)){
        if(!dir){
            q->Items[0] = item;
            q->rear1 = 0;
            q->front1 =0;
        }else{
            q->Items[Half_Size] = item;
            q->rear2 = Half_Size;
            q->front2 = Half_Size;
        }
        return;
    }
    if(!dir){
        q->rear1 = (q->rear1+1) % Half_Size;
        q->Items[q->rear1]= item;
    }else{
        q->rear2 = ((q->rear2+1) % Half_Size) + Half_Size;
        q->Items[q->rear2]= item;
    }
}

int deletecq(int dir,Queue *q){
    if(is_Empty(dir,q)){
        printf("Queue is Empty!");
        return -999;
    }
    int output;
    if(!dir){
        output = q->Items[q->front1];
        if(q->front1 == q->rear1){
            q->front1 = -1;
            q->rear1 = -1;
        }else q->front1 = (q->front1 + 1) % Half_Size;
        return output;
    }else{
        output = q->Items[q->front2];
        if(q->front2 == q->rear2){
            q->front2 = Half_Size - 1;
            q->rear2 = Half_Size - 1;
        }else q->front2 = ((q->front2 + 1) % Half_Size) + Half_Size;
        return output;
    }
}

void displaycq(int dir,Queue *q){
    if(is_Empty(dir,q)){
        printf("Queue is Empty! \n");
        return;
    }
    if(!dir){
        int i = q->front1;
        while (1) {
            printf("%d ", q->Items[i]);
            if (i == q->rear1)break;
            i = (i + 1) % Half_Size;
        }
        printf("\n");
    }else{
        int i = q->front2;
        while (1) {
            printf("%d ", q->Items[i]);
            if (i == q->rear2) break;
            i = ((i + 1) % Half_Size) + Half_Size;
        }
        printf("\n");
    }
}

int main(){
    Queue que;
    Initialize_Queue(&que);
    insertcq(0,&que,1);
    insertcq(1,&que,2);
    insertcq(0,&que,3);
    insertcq(1,&que,4);

    displaycq(0,&que);
    displaycq(1,&que);
    printf("Deleted in dir 0: %d \n",deletecq(0,&que));
    printf("Deleted in dir 1: %d \n",deletecq(1,&que));
    displaycq(0,&que);
    displaycq(1,&que);

    return 0;
}