// BRUTE ============================================== RECURSION ======= TC = O(n) , SC = O(n/k) =======================================================================

// SC = O(n/k) -> Auxilary Stack space taken by recursion. n/k as everytime we reduce 'k' number of nodes and pass the rest so for eg. length of LL = 100 and k=10, so for
// this we will make 10 recurrsive calls which is 100/10 = 10

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

// OPTIMAL ===================================== ITERATIVE ======= TC = O(n) =========================================================================================

class Solution {
public:
    // Normal reversing function
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *c = s, *n = s->next;
        
        while(p != e){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1) return head;
        
        // Add a dummy node before the head and link it to head
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        // As per the algo we need to stand on the previous node of start so we created 'dummy' and pointed 'beforeStart' to it 
        ListNode *beforeStart = dummy, *e = head;
        // 'i' is used to keep a check on when we reach/complete traversing 'k' group of nodes so that we can perform 'reversing' on them
        int i = 0;
        
        while(e != NULL){
            i++;
            
            if(i%k == 0){
                ListNode *s = beforeStart->next, *temp = e->next;
                reverse(s, e);
                // Since on reversing - (s, e) we will get it back as (e, s) so we point beforeStart->next to e
                beforeStart->next = e;
                // As the connection between 'e' and the next node after 'e' is been broken on reversing , we have to restore it as now we have 's' instead of 'e' on reversing
                s->next = temp;
                // Now increment the pointers 'beforeStart' and 'e' so to consider the next kth group of nodes
                beforeStart = s;
                e = temp;
            }
            
            else{
                e = e->next;
            }
        }
        
        // return the head of reversed LL
        return dummy->next;
    }
};
