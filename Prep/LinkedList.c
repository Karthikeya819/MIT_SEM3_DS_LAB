/*Linked List Implementation*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list_node {
    int data;
    struct list_node *link;
} *list_pointer;
list_pointer Create_LinkedList(){
    list_pointer head = (list_pointer)malloc(sizeof(list_pointer));
    int data1;
    printf("Enter Data:");
    scanf("%d",&data1);
    head->data = data1;
    head->link = NULL;
    return head;
}
list_pointer insert_end(list_pointer head){
    list_pointer ptr,new_node;
    new_node = (list_pointer)malloc(sizeof(list_pointer));
    int data;
    printf("Enter Data:");
    scanf("%d",&data);
    new_node->data = data;
    new_node->link = NULL;
    ptr = head;
    while(ptr->link != NULL)ptr=ptr->link;
    ptr->link = new_node;
    return head;
}
list_pointer insert_start(list_pointer head){
    list_pointer new_node = (list_pointer)malloc(sizeof(list_pointer));
    int data;
    printf("Enter Data:");
    scanf("%d",&data);
    new_node->data = data;
    new_node->link = head;
    return new_node;
}
void display(list_pointer head){
    list_pointer ptr;
    ptr = head;
    while(ptr->link != NULL){printf("%d ",ptr->data);ptr = ptr->link;}
    printf("%d",ptr->data);
}

int main(){
    printf("Hello World! \n");
    list_pointer head = Create_LinkedList();
    head = insert_end(head);
    head = insert_end(head);
    head = insert_end(head);
    head = insert_start(head);
    display(head);

    return 0;
}