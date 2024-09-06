/*Evaluate a given postfix expression using stack*/

#include <stdio.h>

//
//Additional Practice Question (Not There in Lab)
//

typedef enum {lparen,rparen,plus,minus,divide,multiply,mod,eos,operand}precedence;

char Stack[100];
int tos = -1;
char expr[100];

precedence get_token(char *symbol,int *n){
    *symbol = expr[(*n)++];
    switch(*symbol){
        case '(': return lparen;break;
        case ')': return rparen;break;
        case '+': return plus;break;
        case '-': return minus;break;
        case '/': return divide;break;
        case '*': return multiply;break;
        case '%': return mod;break;
        case '\0': return eos;break;
        default: return operand;
    }
}

void push(char item){
    Stack[++tos] = item;
}

int eval(){
    precedence token;
    char symbol;
    int op1,op2;
    int n = 0;
    token = get_token(&symbol,&n);
    while(token != '\0'){
        if(token == operand){
            push(symbol);
            printf("%c",symbol);
        }
    }
}

int main(){
    printf("Enter prefix Exp:-");
    scanf("%s",&expr);
    printf("%s",expr);
    eval();
    for(int i = tos;i>=0;i--){
        printf("%c ",Stack[i]);
    }

    return 0;
}

//
//Additional Practice Question (Not There in Lab)
//