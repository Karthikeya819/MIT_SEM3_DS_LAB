/*
Given an array arr with n elements and a number k, k<n. The task is to delete k
elements which are smaller than next element (i.e., we delete arr[i] if arr[i] <
arr[i+1]) or become smaller than next because next element is deleted. Example:
Input: arr[] = {20, 10, 25, 30, 40}, k = 2
Output: 25 30 40
*/

#include <stdio.h>
#define Max_Size 20

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
        printf("%d,",stack->Array[i]);
    }
    printf("\n");
}
void push(STACK *stack,int item){
    if(isFull(stack) == 1){printf("Stack is Full! \n");return;}
    stack->Array[++(stack->tos)] = item;
}
int pop(STACK *stack){
    if(!isEmpty(stack) == 1){return stack->Array[(stack->tos)--];};
}

int main(){
	STACK stack;
    stack.tos = -1;
    int N,K;
	printf("Enter N:");
	scanf("%d",&N);
	int Array[N];
	for(int i = 0;i<N;i++){
		printf("Enter %d Element:-",i+1);
		scanf("%d",&Array[i]);
	}
	printf("Enter K:- ");
	scanf("%d",&K);
    push(&stack, Array[0]);
    for (int i = 1; i < N; i++) {
        while (!isEmpty(&stack) && stack.Array[stack.tos] < Array[i] && K > 0) {
            pop(&stack);
            K--;
        }
        push(&stack, Array[i]);
    }
    while (K > 0 && !isEmpty(&stack)) {
        pop(&stack);
        K--;
    }
    display(&stack);
}
