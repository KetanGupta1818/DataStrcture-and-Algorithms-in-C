//If an array of characters has to be returned from a c function the use of malloc has to be made. 
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct stack{
    int top;
    int capacity;
    int *array;
};
struct stack *create_stack(int capacity){
    struct stack *S = malloc(sizeof(struct stack));
    if(!S){
        printf("Memory error!\n");
        return NULL;
    }
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(capacity*sizeof(int));
    return S;
}
int isEmpty(struct stack *S){
    return (S->top==-1);
}
int isFull(struct stack *S){
    return (S->top == S->capacity-1);
}
void double_stack(struct stack *S){
    S->capacity = S->capacity * 2;
    S->array = malloc(S->capacity*sizeof(int));
}
void push(struct stack *S, char data){
    if(isFull(S))
        double_stack(S);
    S->array[++S->top] = data;
}
char pop(struct stack *S){
    if(isEmpty(S)){
        return '\0';
    }
    return (S->array[S->top--]);
}
int peek(struct stack *S){
    if(isEmpty(S))
        return 0;
    return(S->array[S->top]);
}
int priority(char a){
    if(a=='(')
        return 0;
    if(a=='+' || a=='-')
        return 1;
    if(a=='*' || a=='/'){
        return 2;
    }
}
char* infix_to_postfix(char expression[]){
    char *e,x;
    e = expression;
    char *p;
    p = malloc(strlen(expression)*sizeof(char));
    int i=0;
    struct stack *stk = create_stack(5);
    while(*e!='\0'){
        if(isalnum(*e)){
            p[i] = *e;
            i++;
        }
        else if(*e=='(')
            push(stk,*e);
        else if(*e==')'){
            while((x=pop(stk))!='(')
                p[i] = x;
                i++;
        }
        else{
            while(priority(peek(stk))>=priority(*e)){
                p[i] = pop(stk);
                i++;
            }
            push(stk,*e);
        }
        e++;
    }
    while(!isEmpty(stk)){
        p[i] = pop(stk);
        i++;
    }
    return (char *)p;
}
int Value_of_postfix(char arr[]){
    struct stack *stk = create_stack(10);
    for(int i=0;i<strlen(arr);i++){
        if(isdigit(arr[i])) push(stk, arr[i] - '0');
        else{                   //Operand 
            int first = pop(stk);
            int second = pop(stk);
            switch(arr[i]){
                case '+': push(stk,second+first);break;
                case '-': push(stk,second-first);break;
                case '*': push(stk,second*first);break;
                case '/': push(stk,second/first);break;
            }
        }
    }
    return pop(stk);
}
int Value_of_infix(char arr[]){
    struct stack *Operand = create_stack(10);
    struct stack *Operator = create_stack(10);
    for(int i=0;i<strlen(arr);i++){
        if(isalnum(arr[i])) push(Operand, arr[i] - '0');
        else if(arr[i]=='(') push(Operator, arr[i]);
        else if(arr[i]==')'){
            char x;
            while((x=pop(Operator))!='('){
                int first = pop(Operand);
                int second = pop(Operand);
                switch(x){
                    case '+': push(Operand,second+first);break;
                    case '-': push(Operand,second-first);break;
                    case '*': push(Operand,second*first);break;
                    case '/': push(Operand,second/first);break;
                }        
            }
        } 
        else{
            if(priority(arr[i]) > priority(peek(Operator))) push(Operator, arr[i]);
            else{
                while(priority(peek(Operator))>=priority(arr[i])){
                    char x = pop(Operator);
                    int first = pop(Operand);
                    int second = pop(Operand);
                    switch(x){
                        case '+': push(Operand,second+first);break;
                        case '-': push(Operand,second-first);break;
                        case '*': push(Operand,second*first);break;
                        case '/': push(Operand,second/first);break;
                    }
                }
            }
        }
    }
    while(!isEmpty(Operator)){
        char x = pop(Operator);
        int first = pop(Operand);
        int second = pop(Operand);
        switch(x){
            case '+': push(Operand,second+first);break;
            case '-': push(Operand,second-first);break;
            case '*': push(Operand,second*first);break;
            case '/': push(Operand,second/first);break;
        }
    }
    return pop(Operand);
}
int main(){
    char c[25];
    printf("Enter the expression: ");
    scanf("%s", c);
    printf("\nThe postfix of this expression is:   ");
    char *p = infix_to_postfix(c);
    for(int i=0;i<strlen(p);i++) printf("%c", p[i]);
    printf("\nThe value of expression is: %d", Value_of_postfix(p));
    printf("\nThe value by infix evaluation is: %d", Value_of_infix(p));
    return 0;
}
