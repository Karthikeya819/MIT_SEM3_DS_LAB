/*
You're given the pointer to the head node of a sorted singly linked list, where the data in the nodes is in 
ascending order. Delete as few nodes as possible so that the list does not contain any value more than once 
(deleting duplicates). The given head pointer may be null indicating that the list is empty.
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

void Delete_Duplicates(node_ptr head){
    if(head == NULL)return;
    if(head->link == NULL)return;
    node_ptr ptr,prev_ptr;
    int prev = head->data;
    ptr = head->link;
    prev_ptr = head;
    while(ptr != NULL){
        if(ptr->data == prev){
            prev_ptr->link = ptr->link;
            free(ptr);
            ptr = prev_ptr->link;
        }
        else{
            prev_ptr = ptr;
            ptr = ptr->link;
            prev = prev_ptr->data;
        }
    }
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
    node_ptr head = NULL;
    head = AddItem_End(head,1);
    head = AddItem_End(head,2);
    head = AddItem_End(head,2);
    head = AddItem_End(head,3);
    head = AddItem_End(head,3);
    head = AddItem_End(head,3);
    printf("Original Linked List:");
    display(head);
    Delete_Duplicates(head);
    printf("Duplicates Deleted Linked List:");
    display(head);
    return 0;
}