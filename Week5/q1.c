/*
Implement a menu driven program to define a stack of characters. Include push, pop
and display functions. Also include functions for checking error conditionssuch
as underflow and overflow (ref. figure 1) by defining isEmpty and isFull functions.
Use these function in push, pop and display functions appropriately. Use type defined
structure to define a STACK containing a character array and an integer top. Do not
use global variables.
*/

#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

typedef struct{
    char Array[Max_Size];
    int tos;
}STACK;

int isEmpty(STACK *stack){
    if(stack->tos == -1)return 1;
    else return 0;
}
int isFull(STACK *stack){
    if(stack->tos == Max_Size-1)return 1;
    else return 0;
}
void display(STACK *stack){
    for(int i = stack->tos;i>=0;i--){
        printf("%c\n",stack->Array[i]);
    }
}
void push(STACK *stack,char item){
    if(isFull(stack) == 1){printf("Stack is Full! \n");return;}
    stack->Array[++(stack->tos)] = item;
}
char pop(STACK *stack){
    if(!isEmpty(stack) == 1){return stack->Array[(stack->tos)--];};
}

int main(){
    int Command;
    char temp;
    STACK stack;
    printf("Welcome to STACK! \n");
    printf("Current Max Stack Size : %d \n",Max_Size);
    printf("1) Push an Element to Stack \n2) Pop an Element from Stack \n3) Dispaly Stack \n4) Exit \n");
    while(1){
        printf("Enter Menu No :");
        scanf("%d",&Command);
        if(Command == 4)exit(0);
        else if(Command == 3)display(&stack);
        else if(Command == 2){char out = pop(&stack);};
        else if(Command == 1){
            fflush(stdin);
            printf("    Enter a Char to Stack: ");
            scanf("%c",&temp);
            push(&stack,temp);
        }else{
            printf("Invalid Menu Option! \n");
        }
    }
    
    return 0;
}
