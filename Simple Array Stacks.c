//Simple array implimentation of stack
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
struct stack{
    int capacity;
    int top;
    int *array;
};
struct stack* create_stack(int capacity){
    struct stack*S = malloc(sizeof(struct stack));
    if(!S)
        return NULL;
    S->capacity = capacity;
    S->top = -1;
    S->array = malloc(capacity*sizeof(int));
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
    S->array[++S->top]=data;
}
int pop(struct stack *S){
    if(isEmpty(S)){
        printf("Stack Underflow: The stack is already empty.");
        return INT_MIN;
    }
    else{
        return (S->array[S->top--]);
    }
}
int peek(struct stack *S){
   if(isEmpty(S)){
        printf("Stack Underflow: The stack is already empty.");
    }
    else{
        return (S->array[S->top]); 
    }
}
void delete_stack(struct stack *S){
    if(S){
        if(S->array){
            free(S->array);
            free(S);
            return;
        }
    }
}
int main(){
    struct stack *stk;
    int capacity,ele, i=0,p;
    printf("Enter the number of elements in the stack: ");
    scanf("%d", &capacity);
    stk = create_stack(capacity);
    for(i=0;i<capacity;i++){
        printf("Enter element%d: ", i+1);
        scanf("%d", &ele);
        push(stk,ele);
    }
    printf("After pop function %d is removed \n", pop(stk));
    printf("After pop function %d is removed\n", pop(stk));
    printf("The top element is %d\n", peek(stk));
    printf("The size of the stack is: %d\n", size(stk));
    if(isEmpty(stk))
        printf("The stack is empty.\n");
    else
        printf("The stack is not empty!!\n");
    delete_stack(stk);
    return 0;
}
