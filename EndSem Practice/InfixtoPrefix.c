// infix top PreFIx
#include <stdio.h>
#include <string.h>

typedef struct{
    char Arr[20];
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
    else if(symbol == '*' || symbol == '/')return 2;
    return -1;
}

int main(){
    Stack stack;stack.tos = -1;
    char Infix[20],Prefix[20];
    int j = 0;
    printf("Enter Infix Expression: ");scanf("%s",Infix);
    strrev(Infix);
    for(int i=0;i<strlen(Infix);i++)Infix[i] = (Infix[i] == ')')?'(':(Infix[i]=='(')?')':Infix[i];
    char *e;e = Infix;
    while(*e != '\0'){
        if(*e >= '0' && *e <= '9')Prefix[j++] = *e;
        else if(*e == '(')push(&stack,*e);
        else if(*e == ')'){
            while(stack.Arr[stack.tos] != '(')Prefix[j++] = pop(&stack);
            pop(&stack);
        }else{
            while(get_precedence(stack.Arr[stack.tos]) > get_precedence(*e))Prefix[j++] = pop(&stack);
            push(&stack,*e);
        }
        e++;
    }
    while(stack.tos != -1)Prefix[j++] = pop(&stack);
    Prefix[j++] = '\0';
    printf("Prefix Equation: %s",strrev(Prefix));
    
    return 0;
}