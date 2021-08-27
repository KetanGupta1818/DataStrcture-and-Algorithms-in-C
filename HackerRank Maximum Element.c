//Simple array implimentation of stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack{
    int capacity;
    int top;
    int *Array;
};
struct stack* create_stack(int capacity){
    struct stack*S = malloc(sizeof(struct stack));
    if(!S)
        return NULL;
    S->capacity = capacity;
    S->top = -1;
    S->Array = malloc(capacity*sizeof(int));
    return S;
}
int isEmpty(struct stack *S){
    return (S->top == -1);
}
int size(struct stack *S){
    return (S->top+1);
}
int isFull(struct stack *S){
    return (S->top == S->capacity-1);
}
void push(struct stack *S, int data){
    if(isFull(S)){
        printf("Stack overflow: The stack is already full.\n");
    }
    S->Array[++S->top]=data;
}
int pop(struct stack *S){
    if(isEmpty(S)){
        printf("Stack Underflow: The stack is already empty.");
        return INT_MIN;
    }
    else{
        return (S->Array[S->top--]);
    }
}
int peek(struct stack *S){
   if(isEmpty(S)){
        printf("Stack Underflow: The stack is already empty.");
        return 0;
    }
    else{
        return (S->Array[S->top]); 
    }
}
void delete_stack(struct stack *S){
    if(S){
        if(S->Array){
            free(S->Array);
            free(S);
            return;
        }
    }
}
struct AdvanceStack{
    struct stack *element_stack;
    struct stack *max_stack;
};
struct AdvanceStack* create_advancestack(int capacity){
    struct AdvanceStack *astk = malloc(sizeof(struct AdvanceStack));
    astk->element_stack = create_stack(capacity);
    astk->max_stack = create_stack(capacity); //Can be a problem of Memory Usage
    return astk;
}
void pushA(struct AdvanceStack *astk, int data){
    push(astk->element_stack, data);
    if(isEmpty(astk->max_stack) || peek(astk->max_stack)<=data) push(astk->max_stack, data);
}
int popA(struct AdvanceStack *astk){
    if(isEmpty(astk->element_stack)){
        printf("Error happend: Popping empty stack. ");
        return 0;
    }
    int temp = peek(astk->element_stack);
    if(peek(astk->max_stack) == pop(astk->element_stack)) temp = pop(astk->max_stack);
    return temp;
}
int getMax(struct AdvanceStack *astk){
     return (peek(astk->max_stack));
}
int main(){
    int n, choice, val, val1;
    scanf("%d", &n);
    struct AdvanceStack *astk = create_advancestack(n);
    for(int i=0;i<n;i++){
        scanf("%d", &choice);
        switch(choice){
            case 1:
            scanf("%d", &val);
            pushA(astk, val);
            break;
            case 2:
            val1 = popA(astk);
            break;
            case 3:
            printf("%d\n", getMax(astk));
            break;
        }
    }
}
