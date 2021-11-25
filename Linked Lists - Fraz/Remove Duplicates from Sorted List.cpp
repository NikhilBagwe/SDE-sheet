// ========================== RECURSSIVE =============== TC = O(N), SC = O(N) ==============================================================================================

// SC = O(N) -> because function is called n times in worst case

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        // Pass the remaining LL i.e from head->next to recursion
        ListNode* newHead = deleteDuplicates(head->next);
        
        // Check if the 'head' and 'newHead' values are same or not, if same then only return 'newHead'
        if(head->val == newHead->val){
            return newHead;
        }
        // Connect head to newHead then return 'head'
        else{
            head->next = newHead;
            return head;
        }
    }
};

// ========================== ITERATIVE =============== TC = O(N), SC = O(1) ==============================================================================================

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        
        // Use 'temp' to traverse the list
        ListNode* temp = head;
        
        // Until we reach the end of LL
        while(temp->next != NULL){
            
            // compare the values of current node and next node and if same, change the connections and delete next node
            // Don't move 'temp' ptr to next node as their may be more than 2 duplicate nodes, so stand their only
            if(temp->val == temp->next->val){
                ListNode* del = temp->next;
                temp->next = del->next;
                delete del;
            }
            
            else{
                temp = temp->next;
            }
        }
        
        return head;
    }
};
