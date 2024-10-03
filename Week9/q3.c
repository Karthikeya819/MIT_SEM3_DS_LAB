/*
The students of 2 classes (A and B) are standing in 2 separate lines in ascending order of their 
height. The principle asks the students to combine and join a single line. Write a function merge 
to combine the lines into a single line in ascending order of their height using the singly linked 
list. For example class A: 5->10->15. Class B: 2->3->20 resultant line: 2->3->5->10->15->20. Input 
first line contains 2 integer N1 and N2 as number of students of class A and B respectively. 
Second line contains N1 integers (heights of the students of class A in ascending order) third 
line contains N2 integers (heights of students of class B in ascending order). Output Display Line 
of Class A. Display line of class B. Display the joint class file.  
*/

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

node_ptr Join_Lists(node_ptr A,node_ptr B){
	node_ptr C = NULL;
	node_ptr ptr1,ptr2;
	ptr1 = A;
	ptr2 = B;
	while(ptr1 != NULL && ptr2 != NULL){
		if(ptr1->data >= ptr2->data){
			C = AddItem_End(C,ptr2->data);
			ptr2 = ptr2->link;
		}else{
			C = AddItem_End(C,ptr1->data);
			ptr1 = ptr1->link;
		}
	}
	while(ptr1 != NULL){
		C = AddItem_End(C,ptr1->data);
		ptr1 = ptr1->link;
	}
	while(ptr2 != NULL){
		C = AddItem_End(C,ptr2->data);
		ptr2 = ptr2->link;
	}
	return C;
	
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
	C = Join_Lists(A,B);
	printf("A:");
	display(A);
	printf("B:");
	display(B);
	printf("Joined List:");
	display(C);

	return 0;
}