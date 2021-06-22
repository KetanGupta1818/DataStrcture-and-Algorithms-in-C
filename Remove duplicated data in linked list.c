SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    SinglyLinkedListNode* cur = head;
    if(head==NULL||head->next==NULL)
        return head;
    SinglyLinkedListNode* temp = head->next;
    while(temp!=NULL){
        if(cur->data==temp->data){  //Deletion required
            temp=temp->next;
            free(cur->next);
            cur->next=temp;
            continue;
        }
        cur=temp;
        temp=temp->next;
    }
    return head;
}
