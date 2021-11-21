// BRUTE ================================================== TC = O(n) ======================================================================================

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* temp = head;
        
        // Find the length of LL
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
        
        // Find the middle element position
        int mid = n/2;
        // Point temp back to the 'head'
        temp = head;
        
        // Traverse until youn reach the 'middle' node
        while(mid--){
            temp = temp->next;
        }
        
        return temp;
    }
};


// OPTIMAL =============== Slow and Fast pointer ======================================================================================================================

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // Point both pointers to head of LL
        ListNode *slow = head, *fast = head;
        
        // Check whether fast has reached the last node (fast->next != NULL) or has went beyond the last node (fast != NULL)
        while(fast != NULL && fast->next != NULL){
            // Increment slow by 1 and fast by 2, so by the time fast reaches the last node, slow will be standing exactly at the mid node
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};
