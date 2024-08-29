/*
Determine whether a given string is palindrome or not using stack
*/


#include <stdio.h>
#include <stdlib.h>
#define Max_Size 20

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
	char string[20];
	STACK stack;
	stack.tos = -1;
	printf("Enter String:- ");
	scanf("%s",string);
	for(int i = 0;string[i]!='\0';i++){
		push(&stack,string[i]);
	}
	for(int i = 0;string[i]!='\0';i++){
		char temp = pop(&stack);
		if(temp != string[i]){
			printf("Given String is not a Palindrome! \n");return 0;
		}
	}
	printf("Given String is a Palindrome! \n");



	return 0;
}