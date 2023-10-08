class Solution{
  public:
    // Should return head of the modified linked list
    Node *sortedInsert(struct Node* head, int data) {
        struct Node* node = new Node(data);
        struct Node* curr = head;
        
        if(head->data > data){
            node->next = head;
            return node;
        }
        
        while(curr->next)
        {
            struct Node* temp = curr->next;
            if(temp->data > data)
            {
                node->next = temp;
                curr->next = node;
                return head;
            }
            curr = curr->next;
        }
        curr->next = node;
        return head;
    }
};
