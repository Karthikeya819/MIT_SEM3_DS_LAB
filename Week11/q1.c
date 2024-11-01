/*
1)	Implement Binary Tree (BT) using iterative function and display the elements 
f the BT using recursive in-order, pre-order, post-order traversal methods.
*/

#include <stdio.h>
#include <Stdlib.h>
#define MAX_CAPACITY 20

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}*node_ptr;

typedef struct{
    int tos;
    node_ptr Arr[MAX_CAPACITY];
}NodeStack;

void push(NodeStack *stack,node_ptr item){stack->Arr[++(stack->tos)] = item;};
node_ptr pop(NodeStack *stack){return stack->Arr[(stack->tos)--];}

node_ptr Create_Node(int val){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->left = NULL;new_node->right = NULL;

    return new_node;
}

node_ptr Create_BT(){
    int input,option;
    node_ptr root,ptr,new_node;ptr = NULL;
    NodeStack stack;stack.tos = -1;
    root = (node_ptr)malloc(sizeof(struct Node));
    printf("Enter value at root:");scanf("%d",&input);
    root = Create_Node(input);
    ptr = root;
    printf("1.Enter Right 2.Enter Left 3.Move Up 4.Done \n");
    while(1){
        printf("Enter Menu No: ");scanf("%d",&option);
        switch(option){
            case 1:
                printf("Enter Value: ");scanf("%d",&input);
                new_node = Create_Node(input);
                push(&stack,ptr);
                ptr->right = new_node;
                ptr = ptr->right;                
            break;
            case 2:
                printf("Enter Value: ");scanf("%d",&input);
                new_node = Create_Node(input);
                push(&stack,ptr);
                ptr->left = new_node;
                ptr = ptr->left;   
            break;
            case 3:
                if(stack.tos < 0)printf("Already at root!");
                else{
                    ptr = pop(&stack);printf("Moved Up!\n");
                }
            break;
            case 4:
                return root;
            break;
        }
    }
}

void recInOrder(node_ptr ptr){
    if(ptr != NULL){
        recInOrder(ptr->left);
        printf("%d ",ptr->val);
        recInOrder(ptr->right);
    }
}
void recPreOrder(node_ptr ptr){
    if(ptr != NULL){
        printf("%d ",ptr->val);
        recPreOrder(ptr->left);
        recPreOrder(ptr->right);
    }
}
void recPostOrder(node_ptr ptr){
    if(ptr != NULL){
        recPostOrder(ptr->left);
        recPostOrder(ptr->right);
        printf("%d ",ptr->val);
    }
}

int main(){
    node_ptr root = Create_BT();
    printf("In Order: ");recInOrder(root);
    printf("\nPre Order: ");recPreOrder(root);
    printf("\nPost Order: ");recPostOrder(root);

    return 0;
}