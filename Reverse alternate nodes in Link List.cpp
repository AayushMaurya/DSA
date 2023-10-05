class Solution
{
    public:
    void rearrange(struct Node *odd)
    {
        struct Node *current = odd;
        struct Node *nxt = NULL;
        
        while(current->next)
        {
            struct Node* temp = current->next;
            current->next = temp->next;
            temp->next = nxt;
            nxt = temp;
            if(!current->next){
                current->next = nxt;
                return;
            }
            current = current->next;
        }
        current->next = nxt;
    }
};
