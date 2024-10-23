/*
Reverse a doubly linked list containing words in the data field
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    char *data;
    struct node *prev_link;
    struct node *next_link;
}*node_ptr;

node_ptr Insert_End(node_ptr start, char *item){
    node_ptr new_node = (node_ptr)malloc(sizeof(node_ptr));
    new_node->data = item;new_node->prev_link = NULL;new_node->next_link = NULL;
    if(start == NULL)return new_node;
    node_ptr ptr;
    ptr = start;
    while(ptr->next_link != NULL)ptr = ptr->next_link;
    ptr->next_link = new_node;
    new_node->prev_link = ptr;
    return start;
}

void display(node_ptr start){
    node_ptr ptr;
    ptr = start;
    if(start == NULL)return;
    while(ptr->next_link != NULL){
        printf("%s ",ptr->data);
        ptr = ptr->next_link;
    }
    printf("%s \n",ptr->data);
}

node_ptr Reverse(node_ptr start){
    if(start == NULL)return NULL;
    node_ptr ptr = start;
    node_ptr temp = NULL;
    while (ptr != NULL) {
        temp = ptr->prev_link;
        ptr->prev_link = ptr->next_link;
        ptr->next_link = temp;
        ptr = ptr->prev_link;
    }
    if (temp != NULL)start = temp->prev_link;
    return start;
}

int main(){
    node_ptr start = NULL;
    char str[] = "Karthikeya";
    char str1[] = "Davasam";
    start = Insert_End(start,str);
    start = Insert_End(start,str1);
    printf("Doubly Linked List: ");display(start);
    printf("Reversed Doubly Linked List: ");display(Reverse(start));
    return 0;
}