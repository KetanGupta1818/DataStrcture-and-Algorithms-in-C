//Doubly linked list 
#include<stdio.h>
#include<stdlib.h>
struct dnode{
    int data;
    struct dnode *prev;
    struct dnode *next;
};
void line();
void details(struct dnode*);
struct dnode* add_end(struct dnode*, int);
struct dnode* add_start(struct dnode*, int);
struct dnode* add_any(struct dnode*, int, int);
struct dnode* del_end(struct dnode*);
struct dnode* del_start(struct dnode*);
struct dnode* del_any(struct dnode*, int);
int main(){
    int n,e1,i,d1,d2,d3,pos1,pos2;
    printf("Enter number of Elements: ");
    scanf("%d", &n);
    struct dnode* head = malloc(sizeof(struct dnode));
    printf("Enter Element 1: ");
    scanf("%d", &e1);
    head->prev = NULL;
    head->next = NULL;
    head->data = e1;
    for(i=2;i<=n;i++){
        int e;
        printf("Enter Element %d: ", i);
        scanf("%d", &e);
        head = add_end(head, e);
    }
    printf("A new double linked list is created!!\n");
    details(head);
    line();
    printf("\n\t\t\tOperation 1: Addition of node at end\n");
    printf("Enter the value of data: ");
    scanf("%d", &d1);
    head = add_end(head,d1);
    details(head);
    line();
    printf("\n\t\t\tOperation 2: Addition of node at start\n");
    printf("Enter the value of data: ");
    scanf("%d", &d2);
    head = add_start(head,d2);
    details(head);
    line();
    printf("\n\t\t\tOperation 3: Addition of node at any position\n");
    printf("Enter the value of data: ");
    scanf("%d", &d3);
    printf("Enter the position: ");
    scanf("%d", &pos1);
    head = add_any(head,d3,pos1);
    details(head);
    line();
    printf("\n\t\t\tOperation 4: Deletion of node at any position\n");
    printf("Enter the position of node to be deleted: ");
    scanf("%d", &pos2);
    head = del_any(head,pos2);
    details(head);
    line();
    printf("\n\t\t\tOperation 5: Deletion of node at end\n");
    head = del_end(head);
    details(head);
    line();
    printf("\n\t\t\tOperation 6: Deletion of node at start\n");
    head = del_start(head);
    details(head);
    line();
}
void line(){
    printf("\n----------------------------------------------------------------------------------------------\n");
}
void details(struct dnode* head){
    struct dnode* curr = head;
    int count=0;
    printf("The linked list has follwing elements: \n");
    for(curr=head;curr!=NULL;curr=curr->next){
        count = count + 1;
        printf("%d ", curr->data);
    }
    printf("\nTotal number of nodes is: %d", count);
}
struct dnode* add_end(struct dnode* head, int data){
    struct dnode* cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    struct dnode* temp = malloc(sizeof(struct dnode));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    cur->next = temp;
    temp->prev = cur;
    return head;
}
struct dnode* add_start(struct dnode* head, int data){
    struct dnode* cur = head;
    struct dnode* temp = malloc(sizeof(struct dnode));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    temp->next = cur;
    cur->prev = temp;
    head = temp;
    return head;
}
struct dnode* add_any(struct dnode* head, int data, int n){
    struct dnode* cur = head;
    struct dnode* temp = malloc(sizeof(struct dnode));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = data;
    n--;
    while(--n&&cur->next!=NULL)
        cur=cur->next;
    temp->next=cur->next;
    cur->next=temp;
    cur->next->prev=temp;
    temp->prev=cur;
    return head;
}
struct dnode* del_end(struct dnode* head){
    struct dnode* temp1 = head;
    struct dnode* temp2 = head;
    temp1=temp1->next;
    while(temp1->next!=NULL){
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = NULL;
    free(temp1);
    temp1=NULL;
    return head;
}
struct dnode* del_start(struct dnode* head){
    struct dnode* cur = head;
    head=head->next;
    free(cur);
    cur=NULL;
    return head;
}
struct dnode* del_any(struct dnode* head, int n){
    struct dnode* temp1= head;
    struct dnode* temp2= head;
    temp1=temp1->next;
    int i;
    for(i=1;i<n-1;i++){
        temp2=temp1;
        temp1=temp1->next;
    }
    temp2->next = temp1->next;
    temp1->next->prev = temp2;
    free(temp1);
    temp1 = NULL;
    return head;
}

