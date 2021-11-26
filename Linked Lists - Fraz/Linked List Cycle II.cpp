// ========================= Slow and Fast pointer -> used to return node from which cycle starts and ends =============================================================

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        // Check why we exited from 'while' loop. In some testcases there might me no cycle, so check for that
        if(fast == NULL || fast->next == NULL) return NULL;
        
        // Init 2 pointers pointing to 'slow/fast' and 'head'
        ListNode *ptr1 = slow, *ptr2 = head;
        
        // Move both pointers by 1 everytime.
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
};
