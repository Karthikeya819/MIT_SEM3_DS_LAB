/*Perform UNION and INTERSECTION set operations on singly linked lists with
and without header node*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node *link;
}*node_ptr;

node_ptr AddItem_End(node_ptr start,int item){
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

int Search_Elem(node_ptr start,int item){
	if(start == NULL)return 0;
	node_ptr ptr = start;
	while(ptr->link != NULL){
		if(ptr->data == item)return 1;
		ptr = ptr->link;
	}
	if(ptr->data == item)return 1;
	return 0;
}

node_ptr UNION(node_ptr A,node_ptr B){
	node_ptr unio = NULL;
	node_ptr ptr;
	ptr = A;
	if(ptr != NULL){
		while(ptr->link != NULL){
			if(Search_Elem(unio,ptr->data) == 0)unio = AddItem_End(unio,ptr->data);
			ptr = ptr->link;
		}
		if(Search_Elem(unio,ptr->data) == 0)unio = AddItem_End(unio,ptr->data);
		ptr = ptr->link;
	}
	ptr = B;
	if(ptr != NULL){
		while(ptr->link != NULL){
			if(Search_Elem(unio,ptr->data) == 0)unio = AddItem_End(unio,ptr->data);
			ptr = ptr->link;
		}
		if(Search_Elem(unio,ptr->data) == 0)unio = AddItem_End(unio,ptr->data);
		ptr = ptr->link;
	}
	return unio;
}

node_ptr INTERSECTION(node_ptr A,node_ptr B){
	node_ptr unio = NULL;
	node_ptr ptr;
	ptr = A;
	if(ptr != NULL){
		while(ptr->link != NULL){
			if(Search_Elem(unio,ptr->data) == 0 && Search_Elem(B,ptr->data) == 1)unio = AddItem_End(unio,ptr->data);
			ptr = ptr->link;
		}
		if(Search_Elem(unio,ptr->data) == 0 && Search_Elem(B,ptr->data) == 1)unio = AddItem_End(unio,ptr->data);
		ptr = ptr->link;
	}
	ptr = B;
	if(ptr != NULL){
		while(ptr->link != NULL){
			if(Search_Elem(unio,ptr->data) == 0 && Search_Elem(A,ptr->data) == 1)unio = AddItem_End(unio,ptr->data);
			ptr = ptr->link;
		}
		if(Search_Elem(unio,ptr->data) == 0 && Search_Elem(A,ptr->data) == 1)unio = AddItem_End(unio,ptr->data);
		ptr = ptr->link;
	}
	return unio;
}

void display(node_ptr start){
	node_ptr ptr;
	ptr = start;
	while(ptr->link != NULL){
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("%d \n",ptr->data);
}


int main(){
	node_ptr A = NULL;
	node_ptr B = NULL;
	A = AddItem_End(A,10);
	A = AddItem_End(A,20);
	A = AddItem_End(A,30);
	A = AddItem_End(A,40);
	B = AddItem_End(B,10);
	B = AddItem_End(B,60);

	node_ptr C;
	node_ptr D;
	C = UNION(A,B);
	D = INTERSECTION(A,B);
	printf("A:");
	display(A);
	printf("B:");
	display(B);
	printf("UNION:");
	display(C);
	printf("Intersection:");
	display(D);

	return 0;
}