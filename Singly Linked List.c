//Singly Linked list 
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void count_nodes (struct node *);
void print_data (struct node *);
void add_node_end(struct node*, int);
struct node* add_node_start(struct node*, int); //Returns the head pointer. 
struct node* add_node_any(struct node*, int, int);
struct node* del_node_any(struct node*, int);
struct node* del_node_end(struct node*);
struct node* del_node_start(struct node*);
int main(){
    struct node *head = malloc(sizeof(struct node));
    int n,n1,n2,pos,pos1;
    head->data = 35;
    head->link = NULL;
    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;
    head->link = current;
    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;
    head->link->link = current;
//------------------------------------------------------------------------------------------------------------
    count_nodes(head);
    print_data(head);
    printf("\nEnter the number to be inseted in the linked list at the end: ");
    scanf("%d", &n);
    add_node_end(head, n);
    count_nodes(head);
    print_data(head);
    printf("\nEnter the number to be inseted in the linked list at the start: ");
    scanf("%d", &n1);
    head = add_node_start(head, n1);
    count_nodes(head);
    print_data(head);
    printf("\nEnter the position and Number to be inserted: ");
    scanf("%d%d", &pos, &n2);
    head = add_node_any(head, pos, n2);
    count_nodes(head);
    print_data(head);
    printf("\nEnter the position to be deleted: ");
    scanf("%d", &pos1);
    head = del_node_any(head, pos1);
    count_nodes(head);
    print_data(head);
    head = del_node_start(head);
    count_nodes(head);
    print_data(head);
    head = del_node_end(head);
    count_nodes(head);
    print_data(head);
    return 0;
}
void count_nodes(struct node *head){
    int count=0;
    if(head==NULL)
        printf("The linked list is empty.");
    struct node *ptr = NULL;
    ptr = head;
    while(ptr!=NULL){
        count++;
        ptr = ptr->link;
    }
    printf("The number of nodes are: %d\n", count);
}
void print_data(struct node *head){
    struct node *current = head;
    printf("The data of the linked list are: ");
    for(current=head;current!=NULL;current=current->link)
        printf("%d ", current->data);
    printf("\n");
}
void add_node_end(struct node *head, int data_new){
    struct node *ptr, *temp;
    ptr = head;
    temp = malloc(sizeof(struct node));
    temp->data = data_new;
    temp->link = NULL;
    while(ptr->link!=NULL)
        ptr = ptr->link;
    ptr->link = temp;
}
struct node* add_node_start(struct node*head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = head;
    head = temp;
    return head;
    
}
struct node* add_node_any(struct node*head, int position,int data){
    struct node *temp , *cur = head;
    int c=1;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    position = position - 1;
    while(--position && cur!=NULL)
        cur = cur->link;
    temp->link = cur->link;
    cur->link = temp;
    return head;
}
struct node* del_node_start(struct node *head){
    struct node *temp;
    temp = head;
    printf("\nThe first node is deleted:.....\n");
    head = head->link;
    free(temp);
    temp == NULL ;//As temp is a daggling pointer so its a good practice to set its value to NULL.
    return head;
}
struct node* del_node_end(struct node *head){
    struct node *temp1, *temp2;
    temp1 = head;
    temp2 = head;
    printf("\nThe last node is deleted:.....\n");
    while(temp1->link!=NULL){
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = NULL;
    free(temp1);
    temp1 == NULL;
    return head;
}
struct node* del_node_any(struct node* head, int pos){
    struct node*temp1, *temp2;
    temp1 = head;
    temp2 = head;
    //pos--;
    while(--pos&&temp1->link!=NULL){
        temp2 = temp1;
        temp1 = temp1->link;
    }
    temp2->link = temp1->link;
    free(temp1);
    temp1 == NULL;
    return head;
}
