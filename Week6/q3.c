/*Implement two stacks in an array*/

#include <stdio.h>
#define MAX_SIZE 10

typedef struct{
    int Stack[MAX_SIZE];
    int tos1;
    int tos2;
}Two_Stacks;

int is_Full(Two_Stacks *stack){
    if(stack->tos2 - stack->tos1 <= 1)return 1;
    else return 0;
}

int is_Empty(int dir,Two_Stacks *stack){ //dir-> 0 for Stack 1 and 1 for Stack 2
    if(dir){
        if(stack->tos2 == MAX_SIZE)return 1;
        else return 0;
    }
    if(stack->tos1 == -1)return 1;
    return 0;
}

void push(int dir,Two_Stacks *stack,int item){
    if(dir){
        stack->Stack[--(stack->tos2)] = item;
        return;
    }
    stack->Stack[++(stack->tos1)] = item;
}

Two_Stacks Create_Two_Stacks(){
    Two_Stacks stack;
    for(int i=0;i<MAX_SIZE;i++)stack.Stack[i]=0;
    stack.tos1 = -1;
    stack.tos2 = MAX_SIZE;
    return stack;
}

int pop(int dir,Two_Stacks *stack){
    if(is_Empty(dir,stack)){
            printf("Stack is Empty!");
            return -999;
    }
    if(dir)return stack->Stack[(stack->tos2)++];
    return stack->Stack[(stack->tos1)--];
}

void display(Two_Stacks *stack){
    for(int i = stack->tos1;i>=0;i--){
        printf("%d ",stack->Stack[i]);
    }
    printf("\n");
    for(int i = stack->tos2;i<MAX_SIZE;i++){
        printf("%d ",stack->Stack[i]);
    }
}

int main(){
    Two_Stacks stack = Create_Two_Stacks();
    push(0,&stack,1);
    push(1,&stack,9);
    push(0,&stack,2);
    push(1,&stack,8);
    display(&stack);
    return 0;
}