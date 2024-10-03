/*Implement a queue using singly linked list without header node*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}*node_ptr;



node_ptr EnQueue(node_ptr start,int item){
	node_ptr new_node = (node_ptr) malloc(sizeof(node_ptr));
	new_node->data = item;
	new_node->link = NULL;
	if(start == NULL){
		return new_node;
	}
	node_ptr ptr;
	ptr = start;
	while(ptr->link != NULL){
		ptr = ptr->link;
	}
	ptr->link = new_node;
	return start;
}
node_ptr DeQueue(node_ptr start){
	if(start == NULL){
		printf("Queue is Empty! \n");
		return start;
	}
	printf("%d \n",start->data);
	if(start->link == NULL){
		return NULL;
	}
	node_ptr ptr;
	ptr = start->link;
	free(start);
	return ptr;
}

int main(){
	node_ptr start = NULL;
	start = EnQueue(start,10);
	start = DeQueue(start);
	start = DeQueue(start);
	start = EnQueue(start,20);
	start = EnQueue(start,30);
	start = EnQueue(start,40);
	start = DeQueue(start);

	return 0;
}