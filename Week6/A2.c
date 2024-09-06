/*Convert an infix expression to postfix*/
#include <stdio.h>

//
//Additional Practice Question (Not There in Lab)
//

typedef enum {lparen,rparen,plus,minus,multiply,divide,mod,eos,operand}precedence;

static int isp [] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp [] = {20, 19, 12, 12, 13, 13, 13, 0};

char infix_expr[100];
char Stack_glob[100];

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
        case 0: printf("%c",'(');break;
        case 1: printf("%c",')');break;
        case 2: printf("%c",'+');break;
        case 3: printf("%c",'-');break;
        case 4: printf("%c",'*');break;
        case 5: printf("%c",'/');break;
        case 6: printf("%c",'%');break;
        case 7: printf("%c",'\n');break;
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
            printf("%c",Symbol);
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
}

//
//Additional Practice Question (Not There in Lab)
//