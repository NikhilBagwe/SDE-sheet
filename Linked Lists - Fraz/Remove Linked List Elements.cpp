// BRUTE ==================================================================================================================================

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *tail = dummy;
        
        while(tail != NULL && tail->next != NULL){
            // If node value is same as given 'val' then DELETE the node
            if(tail->next->val == val){
                ListNode *temp = tail->next;
                tail->next = temp->next;
                delete temp;
            }
            
            else tail = tail->next;
        }
        
        return dummy->next;
    }
};

// OPTIMAL ====================== RECURSSIVE CLEAN CODE ===============================================================================================

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        
        // pass the remainig LL from 2nd node i.e next node after head to recursion
        head->next = removeElements(head->next, val);
        
        // Now we have to take care of only the head node - check whether its value is same as 'val', if same then delete it
        if(head->val == val){
            ListNode *ans = head->next;
            delete head;
            return ans;
        }
        
        else return head;
    }
};
