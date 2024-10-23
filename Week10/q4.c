/*
Given two polynomials, write a program to perform the following operations on singly circular linked list 
with header node. Use menu driven approach to input two polynomials, subtract, multiply and display the result.
*/

// Partial Answer
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    int coeff;
    struct node *link;
}*node_ptr;

node_ptr Insert_End(node_ptr head,int data,int coeff){
    if(head == NULL){
        head = (node_ptr)malloc(sizeof(node_ptr));
        head->link = NULL;
    }
    node_ptr new_node = (node_ptr)malloc(sizeof(node_ptr));
    new_node->data = data;new_node->coeff = coeff;new_node->link = NULL;
    if(head->link == NULL){
        head->link = new_node;
        new_node->link = head;
        return head;
    }
    node_ptr ptr;
    ptr = head->link;
    while(ptr->link != head)ptr = ptr->link;
    ptr->link = new_node;
    new_node->link = head;
    return head;
}

void display(node_ptr head){
    if(head == NULL)return;
    if(head->link == NULL)return;
    node_ptr ptr;
    ptr = head->link;
    while(ptr->link != head){
        printf("(%d,%d) ",ptr->data,ptr->coeff);
        ptr = ptr->link;
    }
    printf("(%d,%d) \n",ptr->data,ptr->coeff);
}

int main(){
    node_ptr head = NULL;
    head = Insert_End(head,1,1);
    head = Insert_End(head,1,2);
    display(head);

    return 0;
}
// Partial Answer