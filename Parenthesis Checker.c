//Make equation parser using stacks: Dynamic array.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int capacity;
    int top;
    char *array;
};
struct stack* CreateStack(int capacity){
    struct stack *S = malloc(sizeof(struct stack));
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(S->capacity*sizeof(char));
    return S;
}
int isFull(struct stack *S){
    return (S->top == S->capacity-1);
}
int isEmpty(struct stack *S){
    return (S->top == -1);
}
void DoubleStack(struct stack *S){
    S->capacity*=2;
    S->array = realloc(S->array,S->capacity*sizeof(char));
}
void push(struct stack *S, char data){
    if(isFull(S)) DoubleStack(S);
    S->array[++S->top] = data;   
}
char pop(struct stack *S){
    if(isEmpty(S)){
        printf("Error\n");
        return '\0';
    }
    return S->array[S->top--];
}
char peek(struct stack *S){
    if(isEmpty(S)){
        printf("The stack is empty\n");
        return '\0';
    }
    return S->array[S->top];
}
int isMatch(char a, char b){
    if(a=='[' && b==']') return 1;
    else if(a=='{' && b=='}') return 1;
    else if(a == '(' && b==')') return 1;
    else return 0;
}
int checkExperssion(char expression[]){
    int count;
    char temp;
    struct stack *stk = CreateStack(5);
    for(count=0;count<strlen(expression);count++){
        if(expression[count]=='[' || expression[count]=='(' || expression[count]=='{') push(stk,expression[count]);
        if(expression[count]==']' || expression[count]=='}' || expression[count]==')'){
            if(isEmpty(stk)){
                printf("Symbols in right are greater than in left: \n");
                return 0;
            }
            else{
                temp = pop(stk);
                if(!isMatch(temp,expression[count])){
                    printf("The symbols do not match! %c and %c\n", temp, expression[count]);
                    return 0;
                }
            }
        }
    }
    if(isEmpty){
        printf("The parathesis are matched!\n");
        return 1;
    }
    else{
        printf("The parathesis are not matched.");
    }
}
int main(){
    char arr[20];
    printf("Welcome to parathesis Matcher.\n");
    printf("Enter the expression: ");
    scanf("%s", arr);
    if(checkExperssion(arr)) printf("Valid expression");
    else printf("Invalid expression. ");
    return 0;
}
