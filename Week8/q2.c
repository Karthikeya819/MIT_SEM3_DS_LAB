/*
Implement a queue of strings using an output restricted dequeue (no deleteRight).
Note: An output-restricted deque is one where insertion can be made at both ends,
but deletion can be made from one end only, where as An input-restricted deque is
one where deletion can be made from both ends, but insertion can be made at one
end only.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 10

typedef struct{
	char Arr[Max_Size][20];
	int rear,front;
}Queue;

void Init_Queue(Queue *q){
	q->front = -1;
	q->rear = -1;
}

int is_Full(Queue *q){
	return (q->rear == Max_Size - 1);
}
int is_Empty(Queue *q){
	return (q->front == -1);
}

void Insert_Front(Queue *q,char item[]){
	if(q->front < 1){
		printf("Insertion at front is not Possible!");
		return;
	}
	strcpy(q->Arr[--q->front],item);
}
void Insert_Rear(Queue *q,char item[]){
	if(is_Full(q)){
		printf("Queue is Full!");
		return;
	}
	if(is_Empty(q)){
		q->front = 0;
	}
	strcpy(q->Arr[++q->rear],item);
}
void deque(Queue *q,char *output){
	if(is_Empty(q)){
		printf("Queue is Empty!");
		exit(0);
	}
	strcpy(output,q->Arr[q->front++]);
}

int main(){
	Queue que;
	Init_Queue(&que);
	Insert_Rear(&que,"Karthikeya");
	char output[20];
	deque(&que,&output[0]);
	printf("Dequeue: %s",output);
	return 0;
}