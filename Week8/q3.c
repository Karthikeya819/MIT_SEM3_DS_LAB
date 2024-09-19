/*
Write a program to check whether given string is a palindrome using a dequeue
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max_Size 10

typedef struct{
	char Arr[Max_Size];
	int front,rear;
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

void add_Queue(Queue *q,char item){
	if(is_Full(q)){
		printf("Queue is Full!");
		return;
	}
	if(is_Empty(q)){
		q->front = 0;
	}
	q->Arr[++q->rear] = item;
}
char deque(Queue *q){
	if(is_Empty(q)){
		return '\0';
	}
	char temp = q->Arr[q->front++];
	if(q->front == q->rear+1){
		q->front = -1;
		q->rear = -1;
	}
	return temp;
}

int main(){
	char input[20];
	Queue que;
	Init_Queue(&que);
	printf("Enter a String: ");
	scanf("%s",input);
	int length = strlen(input);
	int mid = (length%2==0)?(length/2)-1:length/2;
	for(int i = length-1;i>mid;i--){
		add_Queue(&que,input[i]);
	}
	for(int i =0;i<length/2;i++){
		char temp = deque(&que);
		if(temp != input[i]){
			printf("Given String is not a Palindrome!");
			exit(0);
		}
	}
	printf("Given String is Palindrome! \n");
	

	return 0;
}