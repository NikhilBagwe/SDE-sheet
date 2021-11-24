// BRUTE ============================================== RECURSION ==============================================================================

class Solution {
public:
    // Normal iterative reversing approach
    void reverse_K_Nodes(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *c = s, *n = s->next;
        
        // Since we are reversing only from 's' to 'e', 'e' will become the head node
        while(p != e){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        // If k=1, then there is no need of reversal so directly return
        if(head == NULL || head->next == NULL || k == 1) return head;
        
        // Init start and end pointer as we have to reverse the first kth nodes ourselves and the remaining will be done by recursion
        ListNode *s = head, *e = head;
        
        // Move/increment end ptr by k-1 nodes
        int inc = k-1;
        while(inc--){
            e = e->next;
            // suppose in case, k=5 and length of LL is 3, so at a point e will become null as it will go out of bound, so check for that
            if(e == NULL) return head;
        }
      
        // As we reversing the first kth nodes, pass the remaing LL i.e after 'e' to recursion and after that call 'reverse_K_Nodes' function
        ListNode *nextHead = reverseKGroup(e->next, k);
        reverse_K_Nodes(s, e);
        
        s->next = nextHead;
        // 'e' will be our new head
        return e;
    }
};
