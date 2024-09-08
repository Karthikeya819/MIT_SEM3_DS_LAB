/*Convert an infix expression to prefix.*/

#include <stdio.h>
#include <string.h>

typedef enum {lparen,rparen,plus,minus,multiply,divide,mod,eos,operand}precedence;

static int isp [] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp [] = {20, 19, 12, 12, 13, 13, 13, 0};

char infix_expr[100];
char Stack_glob[100];
char Output_String[100];
int output_i = 0;

void StringRev(char *infix){
    int length = strlen(infix);
    for(int i = 0;i<=length/2;i++){
        char temp = infix[i];
        infix[i] = infix[length-i-1];
        infix[length-i-1] = temp;
    }
    for(int i = 0;i<length;i++){
        if(infix[i] == '(')infix[i] = ')';
        else if(infix[i] == '(')infix[i] = ')';
    }
}

precedence get_token(char *symbol,int *n){
    *symbol = infix_expr[(*n)++];
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
void print_token(precedence token){
    switch(token){
        case 0: Output_String[output_i++] = '(';break;
        case 1: Output_String[output_i++] = ')';break;
        case 2: Output_String[output_i++] = '+';break;
        case 3: Output_String[output_i++] = '-';break;
        case 4: Output_String[output_i++] = '*';break;
        case 5: Output_String[output_i++] = '/';break;
        case 6: Output_String[output_i++] = '%';break;
        case 7: Output_String[output_i++] = '\0';break;
    }
}

void push(int *tos,char item){
    Stack_glob[++(*tos)] = item;
}
char pop(int *tos){
    return Stack_glob[(*tos)--];
}

int main(){
    printf("Enter Infix Equation:- ");
    scanf("%s",infix_expr); //2*(3+6)
    precedence token;
    int tos = -1;
    Stack_glob[++tos] = eos;
    int n = 0;
    char Symbol;
    for(token=get_token(&Symbol,&n);token!=eos;token=get_token(&Symbol,&n)){
        if(token == operand){
            Output_String[output_i++] = Symbol;
            //printf("%c",Symbol);
        }else if(token == rparen){
            while(Stack_glob[tos] != lparen){
                print_token(pop(&tos));
            }
            tos--;
        }else if(token == lparen){
            push(&tos,token);
        }else{
            while(isp[Stack_glob[tos]] >= icp[token]){
                print_token(pop(&tos));
            }
            push(&tos,token);
        }
    }
    while(Stack_glob[tos]!= eos){
        print_token(pop(&tos));
    }
    for(int i = strlen(Output_String)-1;i>=0;i--){
        printf("%c",Output_String[i]);
    }
}