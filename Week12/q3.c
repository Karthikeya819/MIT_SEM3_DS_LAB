/*
Given a Binary Tree and a key, write a function that prints all the ancestors of the key in the given binary tree.
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
int Acenstors(node_ptr root, int x) {
    if (root == NULL)return 0;
    if (root->val == x)return 1;
    if (Acenstors(root->left,x) || Acenstors(root->right,x)) {
        printf("%d ",root->val);
        return 1;
    }
    return 0;
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
    printf("Enter Element to find Acenstors: ");scanf("%d",&in1);
    printf("Acenstors of %d are ",in1);Acenstors(root,in1);
}