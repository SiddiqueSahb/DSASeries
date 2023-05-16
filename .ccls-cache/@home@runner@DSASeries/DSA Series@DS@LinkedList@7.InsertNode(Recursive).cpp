Node* insertNodeRec(Node *head, int i, int data) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    if(head==NULL)
        return NULL;
    if(i==0){
        Node* temp=new Node(data);
        temp->next=head;
        return temp;
    }
    
    if(i==1){
        Node* temp=new Node(data);
        temp->next=head->next;
        head->next=temp;
        return head;
    }
    Node* curr=insertNodeRec(head->next,i-1,data);
    
    return head;
    
}