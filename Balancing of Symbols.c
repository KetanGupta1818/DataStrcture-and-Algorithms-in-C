#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
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
int compare(char a, char b){
    if(a == '(' && b == ')')
        return 1;
    else if(a == '{' && b == '}')
        return 1;
    else if(a == '[' && b == ']')
        return 1;
    return 0;
}
char pop(struct stack *S){
    if(isEmpty(S)){
        printf("The stack is empty. \n");
        return '\0';
    }
    return (S->array[S->top--]);
}
int check_expression(char expression[]){
    int count = 0;
    struct stack *stk = create_stack(5);
    char temp;
    for(count=0;count<strlen(expression);count++){
        if(expression[count] == '[' || expression[count] == '{' || expression[count] == '(')
            push(stk, expression[count]);
        if(expression[count] == ']' || expression[count] == '}' || expression[count] == ')'){
            if(isEmpty(stk)){
                printf("The right hand brackets exceed the left hand brackets.\n");
                return 0;
            }
            temp = pop(stk); //temp is the opening brackets and expression[count] is the closing brackets.
        if(compare(temp, expression[count])){            
            printf("The brackets are matched.\n");
            return 1;
        }
        else{
            printf("The brackerts are not matched.\n");
            return 0;
        }
        }
    }
}
int main(){
    char c[25];
    int i;
    printf("Enter the expression:  ");
    scanf(" %s", c);
    int validity;
    validity = check_expression(c);
    if(validity == 1){
        printf("The expression is valid.\n");
        return 0;
    }
    else{
        printf("The expression is not valid.\n");
        return 0;
    }
}
