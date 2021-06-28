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
void infix_to_postfix(char expression[]){
    char *e,x;
    e = expression;
    struct stack *stk = create_stack(5);
    while(*e!='\0'){
        if(isalnum(*e))
            printf("%c", *e);
        else if(*e=='(')
            push(stk,*e);
        else if(*e==')'){
            while((x=pop(stk))!='(')
                printf("%c", x);
        }
        else{
            while(priority(peek(stk))>=priority(*e))
                printf("%c", pop(stk));
            push(stk,*e);
        }
        e++;
    }
    while(!isEmpty(stk)){
        printf("%c", pop(stk));
    }
}
int main(){
    char c[25];
    printf("Enter the expression: ");
    scanf("%s", c);
    printf("\nThe postfix of this expression is:   ");
    infix_to_postfix(c);
}
