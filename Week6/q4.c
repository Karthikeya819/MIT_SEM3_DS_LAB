/*To convert a prefix expression to postfix using stack*/

#include <stdio.h>
#include <string.h>

char Stack_glob[50][50];
char prefix_exp[50];

int is_opeartor(char Symbol){
    switch(Symbol){
        case '(': return 1;break;
        case ')': return 1;break;
        case '+': return 1;break;
        case '-': return 1;break;
        case '/': return 1;break;
        case '*': return 1;break;
        case '%': return 1;break;
        case '\0': return 1;break;
        default: return 0;
    }
}

void push(int *tos,char item[]){
    strcpy(Stack_glob[++(*tos)],item);
}
void pop(int *tos,char *Output){
    strcpy(Output,Stack_glob[(*tos)--]);
}

int prefix_to_postfix(){
    int tos = -1;
    for(int i = strlen(prefix_exp)-1;i>=0;i--){
        char token = prefix_exp[i];
        if(!is_opeartor(token)){
            char temp[50];
            temp[0] = token;
            temp[1] = '\0';
            push(&tos,temp);
        }else{
            char op1[50];
            pop(&tos,op1);
            char op2[50];
            pop(&tos,op2);
            char Operator[10];
            Operator[0] = token;
            Operator[1] = '\0';
            strcat(op2,Operator);
            strcat(op1,op2);
            push(&tos,op1);
        }
    }
    return tos;
}

int main(){
    printf("Enter Prefix:- ");
    scanf("%s",&prefix_exp);
    int tos = prefix_to_postfix();
    char result[50];
    pop(&tos,result);
    printf("%s",result);
    return 0;
}