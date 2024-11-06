/*
Given a BST, write a function to find the in - order successor of a node.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node *left;
    struct Node *right;
}*node_ptr;

node_ptr Create_Node(int val){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->val = val;
    new_node->left = NULL;new_node->right = NULL;
    return new_node;
}

node_ptr Insert_BST(node_ptr root,int item){
    node_ptr new_node = Create_Node(item);
    if(root == NULL)return new_node;
    node_ptr parent,ptr;
    parent = NULL;ptr = root;
    while(ptr != NULL){
        if(ptr->val > item){
            parent = ptr;ptr = ptr->left;
        }else if(ptr->val < item){
            parent = ptr;ptr = ptr->right;
        }else{
            printf("Insertion of %d Failed due to Duplicate \n",item);return root;
        }
    }
    if(parent->val < item)parent->right = new_node;
    else if(parent->val > item)parent->left = new_node;
    else printf("Insertion of %d Failed due to Duplicate \n",item);

    return root;
}

void InOrder(node_ptr root,int Node, int *print){
    if (root != NULL) {
        InOrder(root->left,Node,print);
        if(*print == 1){printf("%d ",root->val);*print = 0;}
        if(Node == root->val)*print = 1;
        InOrder(root->right,Node,print);
    }
}

int main(){
    node_ptr root;
    int print = 0;
    root = NULL;
    int in1,in2;
    printf("Enter No of Integers: ");scanf("%d",&in1);
    for(int i = 0;i<in1;i++){
        printf("Enter %d Number: ",i+1);scanf("%d",&in2);
        root = Insert_BST(root,in2);
    }
    printf("Enter Element to find InOrder successor: ");scanf("%d",&in1);
    printf("InOrder Successor of %d is ",in1);InOrder(root,in1,&print);
    return 0;
}