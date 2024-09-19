/*
Implement an ascending priority queue.
An ascending priority queue is a collection of items into which items can be
inserted arbitrarily and from which only the smallest item can be removed. If apq is
an ascending priority queue, the operation pqinsert(apq,x) inserts element x into apq
and pqmindelete(apq) removes the minimum element from apq and returns its value.
*/

#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

typedef struct{
	int Arr[Max_Size];
	int rear;
}APQ;

void Init_APQ(APQ *q){
	q->rear = -1;
}
int is_Empty(APQ *q){
	return (q->rear == -1);
}
int is_Full(APQ *q){
	return (q->rear == Max_Size-1);
}
void apqinsert(APQ *q,int item){
	if(is_Full(q)){
		printf("Queue is Full!");
		return;
	}
	q->Arr[++(q->rear)] = item;
}
int apqmindelete(APQ *q){
	if(is_Empty(q)){
		printf("Queue is Empty!");
		exit(0);
	}
	int Small_Index = 0;
	for(int i = 0;i <= q->rear;i++){
		if(q->Arr[i] < q->Arr[Small_Index])Small_Index=i;
	}
	int output = q->Arr[Small_Index];
	for(int i = Small_Index+1;i<=q->rear;i++){
		q->Arr[i-1] = q->Arr[i];
	}
	q->rear--;

	return output;

}

int main(){
	APQ que;
	Init_APQ(&que);
	apqinsert(&que,10);
	apqinsert(&que,5);
	apqinsert(&que,6);
	apqinsert(&que,3);
	apqinsert(&que,4);

	printf("Output: %d \n",apqmindelete(&que));
	printf("Output: %d \n",apqmindelete(&que));
	printf("Output: %d \n",apqmindelete(&que));


	return 0;
}