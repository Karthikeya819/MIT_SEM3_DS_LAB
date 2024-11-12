#include <stdio.h>

typedef struct{
    char Arr[30];
    int tos;
}Stack;
void push(Stack *stack,char item){
    stack->Arr[++(stack->tos)] = item;
}
char pop(Stack *stack){
    return stack->Arr[(stack->tos)--];
}

int get_precedence(char symbol){
    if(symbol == '(')return 0;
    else if(symbol == '+' || symbol == '-')return 1;
    else if(symbol == '*' || symbol == '/')return 1;
    return -1;
}

int main(){
    Stack stack;
    stack.tos = -1;
    char infix[30];
    printf("Enter Infix Expression: ");scanf("%s",infix);
    char *e;
    e = infix;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9')printf("%c",*e);
        else if(*e == '(')push(&stack,*e);
        else if(*e == ')'){
            while(stack.Arr[stack.tos] != '(')printf("%c",pop(&stack));
            pop(&stack);
        }else{
            while(get_precedence(stack.Arr[stack.tos])>=get_precedence(*e)){
                printf("%c",pop(&stack));
            }
            push(&stack,*e);
        }
        e++;
    }
    while(stack.tos != -1)printf("%c",pop(&stack));

    return 0;
}