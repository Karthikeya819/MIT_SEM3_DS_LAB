/*
Evaluate a given prefix expression using stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max_Size 50

typedef struct{
    int Array[Max_Size];
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
        printf("%d ",stack->Array[i]);
    }
}
void push(STACK *stack,int item){
    if(isFull(stack) == 1){printf("Stack is Full! \n");return;}
    stack->Array[++(stack->tos)] = item;
}
int pop(STACK *stack){
    if(!isEmpty(stack) == 1){return stack->Array[(stack->tos)--];};
}

int main(){
	char infix[50];
	STACK stack;
	stack.tos = -1;
	printf("Enter Prefix Equation:- ");
	scanf("%s",infix);
	int infix_len = strlen(infix);
	for(int i = infix_len-1;i>=0;i--){
		if(infix[i] >= '0' && infix[i] <= '9'){
			push(&stack,infix[i]-'0');
		}else{
			int op1 = pop(&stack);
			int op2 = pop(&stack);
			switch(infix[i]){
				case '+': push(&stack,op1 + op2);break;
				case '-': push(&stack,op1 - op2);break;
				case '*': push(&stack,op1 * op2);break;
				case '/': push(&stack,op1 / op2);break;
				default: printf("Invalid Operator Found!");
			}
		}
	}
	display(&stack);

	return 0;
}
