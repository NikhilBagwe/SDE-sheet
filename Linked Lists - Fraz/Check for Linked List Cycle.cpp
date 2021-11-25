// BRUTE ======================================== HASHING ==============================================================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<int, int> m;
        
        ListNode *temp = head;
        
        while(temp != NULL){
            // Check if the current node's value already exists in hashmap
            if(m[temp->val]) return true;
            
            else{
                m[temp->val]++;
                temp = temp->next;
            }
        }
        
        return false;
    }
};

// OPTIMAL ============================ SLOW AND FAST POINTER ===================================================================================================

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        
        return false;
    }
};
