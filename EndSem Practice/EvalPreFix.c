//Evaluate Prefix Equation

#include <stdio.h>
#include <string.h>

typedef struct{
    int Arr[20],tos;
}Stack;

void push(Stack *stack,int item){
    stack->Arr[++(stack->tos)] = item;
}

int pop(Stack *stack){
    return stack->Arr[(stack->tos)--];
}

int main(){
    Stack stack;stack.tos = -1;
    char PreFix[20];
    printf("Enter Prefix Expression: ");scanf("%s",PreFix);
    strrev(PreFix);
    char *e;e=PreFix;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9')push(&stack,*e-'0');
        else{
            int op1 = pop(&stack);int op2 = pop(&stack);
            switch(*e){
                case '+':
                    push(&stack,op1+op2);
                break;
                case '-':
                    push(&stack,op1-op2);
                break;
                case '*':
                    push(&stack,op1*op2);
                break;
                case '/':
                    push(&stack,op1/op2);
                break;
                case '%':
                    push(&stack,op1%op2);
                break;
            }
        }
        e++;
    }
    printf("Result of PreFix Equation is %d",pop(&stack));
    return 0;
}