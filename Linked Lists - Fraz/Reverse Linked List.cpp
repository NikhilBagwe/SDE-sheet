// ============================== ITERATIVE APPROACH ===============================================================================================================

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Check if there is only one node in the list
        if(head == NULL) return NULL;
        
        ListNode *prev = NULL, *current = head, *next1 = head->next;
        
        while(current != NULL){
            // Reverse the connection of current node i.e make it point to previous node
            current->next = prev;
            // Move prev and current by 1
            prev = current;
            current = next1;
            if(next1 != NULL) next1 = next1->next;
        }
        
        // On traversing the LL, 'prev' will be pointing at the new head i.e the tail node of list before reversing it
        return prev;
    }
};

// ================================ RECURSSIVE APPROACH ========================================================================================================

class Solution {
public:
    ListNode* reverse(ListNode* head){
        if(head->next == NULL){
            return head;
        }
        
        ListNode* reverseHead = reverse(head->next);
        // Reverse the connection 
        head->next->next = head;
        // As the 'head' node of LL 'before reversing' is going to become the 'tail' node 'on reversing', make it point to NULL
        head->next = NULL;
      
        return reverseHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        return reverse(head);
    }
};
