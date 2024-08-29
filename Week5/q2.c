/*
Convert a given decimal number to binary using stack.
*/

#include <stdio.h>
#include <stdlib.h>
#define Max_Size 10

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
	int num;
	STACK stack;
	stack.tos = -1;
	printf("Enter Number in Dec:- ");
	scanf("%d",&num);
	while(num!=0){
		push(&stack,num%2);
		num /=2;
	}
	display(&stack);
	return 0;
}