//Evaluate Postfix Equation

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
    char PostFix[20];
    printf("Enter Postfix Expression: ");scanf("%s",PostFix);
    char *e;e=PostFix;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9')push(&stack,*e-'0');
        else{
            int op2 = pop(&stack);int op1 = pop(&stack);
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
    printf("Result of PostFix Equation is %d",pop(&stack));
    return 0;
}