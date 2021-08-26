#include<stdio.h>
#include<stdlib.h>
struct MultipleStack{
    int top1, top2;
    int capacity;
    int *array;
};
struct MultipleStack* CreateMultipleStack(int capacity){
    struct MultipleStack* mstk = (struct MultipleStack*)malloc(sizeof(struct MultipleStack));
    if(!mstk){
        printf("Memory Error!\n");
        return NULL;
    }
    mstk->capacity = capacity;
    mstk->top1 = -1;
    mstk->top2 = capacity;
    mstk->array = (int *)malloc(mstk->capacity*sizeof(int));
    return mstk;
}
int isEmpty(struct MultipleStack* mstk, int StackNumber){
    if(StackNumber==1) return(mstk->top1 == -1);
    else return(mstk->top2 == mstk->capacity);
}
int size(struct MultipleStack* mstk, int StackNumber){
    if(StackNumber == 1) return(mstk->top1+1);
    else return(mstk->capacity - mstk->top2);
}
int isFull(struct MultipleStack* mstk){
    return (size(mstk,1)+size(mstk,2) == mstk->capacity);
}
void push(struct MultipleStack* mstk, int StackNumber, int data){
    if(isFull(mstk)){
        printf("The Stack is Full!");
        return;
    }
    if(StackNumber == 1) mstk->array[++mstk->top1] = data;
    else mstk->array[--mstk->top2] = data;
}
int pop(struct MultipleStack* mstk, int StackNumber){
    if(StackNumber == 1){
        if(isEmpty(mstk, 1)){
            printf("\nCannot pop: The stack is empty.");
            return 0;
        }
        return(mstk->array[mstk->top1--]);
    }
    else{
        if(isEmpty(mstk, StackNumber)){
            printf("\nCannot pop: The stack is empty. ");
            return 0;
        }
        return(mstk->array[mstk->top2++]);
    }
}
int peek(struct MultipleStack* mstk, int StackNumber){
    if(StackNumber == 1){
        if(isEmpty(mstk, 1)){
            printf("\nCannot peek: The stack is empty.");
            return 0;
        }
        return(mstk->array[mstk->top1]);    
    } 
    else{
        if(isEmpty(mstk, StackNumber)){
            printf("\nCannot peek: The stack is empty. ");
            return 0;
        }
        return(mstk->array[mstk->top2]);    
    } 
}
void PrintStack(struct MultipleStack* mstk){
    int p = mstk->top1;
    printf("First Stack is: ");
    for(int i=p;i>=0;i--){
        printf("%d", mstk->array[i]);
    } 
    p = mstk->top2;
    printf("\nSecond Stack is: ");
    for(int i=p;i<mstk->capacity;i++){
        printf("%d", mstk->array[i]);
    } 
}
void print_line(){
    printf("\n---------------------------------------------------------------------------------------");
}
int main(){
    int n;
    printf("Two Stacks implemented in one array.\n");
    printf("1: Push\n2: Pop\n3: Peek\n4: Size\n");
    printf("Input Format: Operation_number Stack_number\n");
    printf("Enter Number of Operations: ");
    scanf("%d", &n);
    print_line();
    struct MultipleStack* mstk = CreateMultipleStack(30);
    print_line();
    for(int i=0;i<n;i++){
        int op, sk_no, val;
        printf("\t\t\t\tOperation Number is %d: ", i+1);
        printf("Enter Operation Number and Stack Number. \n");
        scanf("%d%d",&op,&sk_no);
        switch(op){
            case 1:
            printf("Enter the value to be pushed: ");
            scanf("%d", &val);
            push(mstk,sk_no,val);
            break;
            case 2:
            val = pop(mstk, sk_no);
            printf("\nThe value poped is %d", val);
            break;
            case 3:
            val = peek(mstk, sk_no);
            printf("\nThe current value at stack is: %d", val);
            break;
            case 4:
            val = size(mstk, sk_no);
            printf("\nThe size of stack is: %d", val);
            break;
        }
        print_line();
        PrintStack(mstk);
        print_line();
    }
    printf("\n\nThank You for using Stack.");
    return 0;
}
