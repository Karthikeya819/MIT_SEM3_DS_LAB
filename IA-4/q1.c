#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 20

typedef struct Node{
    char data[20];
    int result;
    struct Node *next;
    struct Node *prev;
}*node_ptr;

typedef struct{
    int Arr[MAX_SIZE];
    int tos;
}Stack;

void push(Stack *stack,int item){stack->Arr[++(stack->tos)]=item;}
int pop(Stack *stack){return stack->Arr[(stack->tos)--];}

node_ptr Insert(node_ptr head,char data[],int result){
    node_ptr new_node = (node_ptr)malloc(sizeof(struct Node));
    strcpy(new_node->data,data);new_node->result = result;
    new_node->next = NULL;new_node->prev = NULL;

    if(head == NULL)return new_node;

    head->prev = new_node;
    new_node->next = head;
    return new_node;    
}

void Display(node_ptr head){
    if(head == NULL)return;
    node_ptr ptr;
    ptr = head;
    while(ptr->next != NULL){
        if(ptr->result == -998)printf("[%s] -> ",ptr->data);
        else printf("[%s,%d] -> ",ptr->data,ptr->result);
        ptr = ptr->next;
    }
    printf("[%s,%d]",ptr->data,ptr->result);
}

int Compute(char Exp[],int prefix){
    int len = strlen(Exp);
    Stack stack;stack.tos = -1;
    if(prefix == 1){
        // Compute Prefix Equation
        for(int i = len-1;i>=0;i--){
            if(Exp[i]>='0' && Exp[i]<='9')push(&stack,Exp[i]-'0');
            else{
                int result = 0;
                int op2 = pop(&stack);
                int op1 = pop(&stack);
                if(Exp[i] == '+')result = op2 + op1;
                else if(Exp[i] == '-')result = op2 - op1;
                else if(Exp[i] == '*')result = op2 * op1;
                else if(Exp[i] == '/')result = op2 / op1;
                else if(Exp[i] == '%')result = op2 % op1;
                push(&stack,result);
            }
        }
        return pop(&stack);
    }else{
        // Compute Postfix Equation
        for(int i = 0;i<len;i++){
            if(Exp[i]>='0' && Exp[i]<='9')push(&stack,Exp[i]-'0');
            else{
                int result = 0;
                int op1 = pop(&stack);
                int op2 = pop(&stack);
                if(Exp[i] == '+')result = op2 + op1;
                else if(Exp[i] == '-')result = op2 - op1;
                else if(Exp[i] == '*')result = op2 * op1;
                else if(Exp[i] == '/')result = op2 / op1;
                else if(Exp[i] == '%')result = op2 % op1;
                push(&stack,result);
            }
        }
        return pop(&stack);
    }
}

int CheckExpression(char Exp[]){
    //Stack stack;stack.tos = -1;
    int roundf = 0;
    int len = strlen(Exp);
    for(int i = 0;i<len;i++){
        if(Exp[i] == '(')roundf++;
        else if(Exp[i] == ')')roundf--;
    }
    if(roundf == 0)return 1;
    return 0;
}

int main(){
    node_ptr head;
    head = NULL;
    int input;
    char Str[20];char Str1[20];
    node_ptr ptr;
    while(1){
        printf("1. Insert Node 2. Display Doubly Linked List 3. Evaluate Linked List 4. Exit \n");
        printf("Enter Menu No: ");scanf("%d",&input);
        switch(input){
            case 1:
                printf("    Enter Tag: ");scanf("%s",Str);
                printf("    Enter Content: ");scanf("%s",Str1);
                head = Insert(head,Str1,-999);head = Insert(head,Str,-998);
                break;
            case 2:
                Display(head);printf("\n");
                break;
            case 3:
                ptr = head;
                while(ptr->next != NULL){
                    if(strcmp(ptr->data,"<TEST>")==0)ptr->next->result = CheckExpression(ptr->next->data);
                    else if(strcmp(ptr->data,"<POSTFIX>")==0)ptr->next->result = Compute(ptr->next->data,0);
                    else if(strcmp(ptr->data,"<PREFIX>")==0)ptr->next->result = Compute(ptr->next->data,1);
                    ptr = ptr->next;
                    if(ptr->next == NULL){break;}
                    ptr = ptr->next;
                }
                printf("Evaluated Doubly Linked List!\n");
                break;
            case 4:
                return 0;
        }
        
    }
    // head = Insert(head,"Karthikeya");
    // head = Insert(head,"Vasistha");
    // head = Insert(head,"Akshay");
    // Display(head);
    // Stack stack;
    // stack.tos = -1;
    // push(&stack,'c');
    // push(&stack,'d');
    // printf("Popped Element: %c",pop(&stack));
    // printf("Balance Expression: %d ",CheckExpression("(Kart(h(i)keya))"));
    // printf("PostFix Result: %d",Compute("23-",0));
    // printf("Prefix Result: %d",Compute("-32",1));
    return 0;
}