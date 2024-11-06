/*
1)	Write a menu driven program to do the following using iterative functions:
i.To create a BST for a given set of integer numbers
ii.To delete a given element from BST .
Note: Replace the element to be deleted with the largest element in the LST (Left Sub Tree) ) when the node to be deleted has both LST (Left Sub Tree) and RST (Right Sub Tree).
iii.To display the elements using in-order traversal.
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

void Delete_Element(node_ptr root, int item){
    node_ptr ptr,parent,q;
    ptr = root;parent = NULL;q = NULL;
    if(root == NULL)return;
    while(ptr != NULL){
        if(ptr->val < item){
            parent = ptr;
            ptr = ptr->right;
        }else if(ptr->val > item){
            parent = ptr;
            ptr = ptr->left;
        }else break;
    }
    if(ptr == NULL){
        printf("Item not Found!");return;
    }
    if(ptr->left == NULL && ptr->right == NULL)q = NULL;
    else if(ptr->left != NULL && ptr->right == NULL)q = ptr->left;
    else if(ptr->left == NULL && ptr->right != NULL)q = ptr->right;
    else{
        // Replace by largest element in its left sub tree
        parent = q;
        q = ptr->left;
        while(q->right != NULL){
            parent = q;
            q = q->right;
        }
        ptr->val = q->val; 
        ptr = q;q = NULL;
    }
    if(parent->val < ptr->val)parent->right = q;
    else parent->left = q;
    free(ptr);
}

void InOrder(node_ptr root){
    if (root != NULL) {
        InOrder(root->left);
        printf("%d ",root->val);
        InOrder(root->right);
    }
}

int main(){
    node_ptr root;
    root = NULL;
    int in1,in2;
    printf("Enter No of Integers: ");scanf("%d",&in1);
    for(int i = 0;i<in1;i++){
        printf("Enter %d Number: ",i+1);scanf("%d",&in2);
        root = Insert_BST(root,in2);
    }
    printf("InOrder Traversal: ");InOrder(root);
    printf("\nEnter Element to Delete: ");scanf("%d",&in1);
    Delete_Element(root,in1);
    printf("InOrder Traversal: ");InOrder(root);
    return 0;
}