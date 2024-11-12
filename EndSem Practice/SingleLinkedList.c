// Single Linked List without header node
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}*node_ptr;

node_ptr Create_Node(int value){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->value = value;new_node->next = NULL;
    return new_node;
}

node_ptr Insert_Beg(node_ptr root,int item){
    node_ptr new_node = Create_Node(item);
    if(root == NULL)return new_node;
    new_node->next = root;
    return new_node;
}

node_ptr Insert_End(node_ptr root,int item){
    node_ptr new_node = Create_Node(item);
    if(root == NULL)return new_node;
    node_ptr ptr;
    ptr = root;
    while(ptr->next != NULL)ptr = ptr->next;
    ptr->next = new_node;
    return root;
}

node_ptr Delete_End(node_ptr root){
    if(root == NULL)return NULL;
    if(root->next == NULL){
        free(root);
        return NULL;
    }
    node_ptr ptr1,ptr2;
    ptr1 = NULL;ptr2 = root;
    while(ptr2->next != NULL){
        ptr1 = ptr2;
        ptr2 = ptr2->next;
    }
    ptr1->next = NULL;
    free(ptr2);
    return root;
}

void display(node_ptr root){
    if(root == NULL){
        printf("Single Linked List is Empty! \n");
        return;
    }
    while(root->next != NULL){
        printf("%d -> ",root->value);
        root = root->next;
    }
    printf("%d \n",root->value);
}

int main(){
    node_ptr root;
    root = NULL;
    root = Insert_End(root,1);
    root = Insert_End(root,2);
    root = Insert_End(root,3);
    root = Delete_End(root);
    display(root);


    return 0;
}