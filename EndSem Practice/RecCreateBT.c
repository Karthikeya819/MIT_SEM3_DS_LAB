// Craete a Binary Tree using Recursion

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *left,*right;
}*node_ptr;

node_ptr Create_Node(int value){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    new_node->value = value;
    new_node->left = NULL;new_node->right = NULL;
    return new_node;
}

node_ptr Create_BT(int item){
    int x;
    if(item != -1){
        node_ptr new_node = Create_Node(item);

        printf("Enter Left Child of %d :",item);scanf("%d",&x);
        new_node->left = Create_BT(x);

        printf("Enter Right Child of %d :",item);scanf("%d",&x);
        new_node->right = Create_BT(x);

        return new_node;
    }
    return NULL;
}


int main(){
    int root;
    printf("Enter Value at root: ");scanf("%d",&root);
    node_ptr tree = Create_BT(root);

    return 0;
}