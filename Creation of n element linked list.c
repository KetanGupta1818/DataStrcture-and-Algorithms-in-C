//Create a n element linked list with add_end fuction
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node* add_end(struct node*, int, int);
void print_nodes(struct node*);
int main(){
    int n,i,n1;
    printf("Enter the number of element in the linked list: ");
    scanf("%d", &n);
    struct node *head = malloc(sizeof(struct node));
    printf("Enter element 1: ");
    scanf("%d", &n1);
    head->data = n1;
    head->link = NULL;
    for(i=1;i<n;i++){
        int element;
        printf("Enter element %d: ", i+1);
        scanf("%d", &element);
        head = add_end(head, i+1, element);
    }
    print_nodes(head);
}
struct node* add_end(struct node *head, int num, int data){
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while(ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
    return head;
}
void print_nodes(struct node *head){
    struct node *cur = head;
    printf("The elements of the linkrd list are\n");
    for(cur=head;cur!=NULL;cur=cur->link)
        printf("%d ", cur->data);
    
}
