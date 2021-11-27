// BRUTE ============================================== TC = O(n) , SC = O(n) ==========================================================================

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        
        // Traverse the LL and store all node values into vector 'v'
        ListNode *temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp = temp->next;
        }
        
        // Compare the first and last values in array and so on
        int s=0, e=v.size()-1;
        while(s <= e){
            if(v[s] == v[e]){
                s++;
                e--;
            }
            else return false;
        }
        
        return true;
    }
};

// OPTIMAL =========================================== TC = O(n) , SC = O(1) ==========================================================================

/*
- Here we are reversing the LL from middle node and then comparing the first node with the mid node and so on.
- eg: 1 2 3 3 2 1
      on reversing = 1 2 3 1 2 3
*/

class Solution {
public:
    ListNode* reverseList(ListNode *head){
        if(head == NULL) return NULL;
        
        ListNode *p = NULL, *c = head, *n = head->next;
        
        while(c != NULL){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
        
        return p;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        
        // We have to reach/stand at previous node of mid node so we change the condition a bit
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Now we will reverse the list from 'slow->next' i.e middle node till last node and attach it back to 'slow->next'
        slow->next = reverseList(slow->next);
        
        // now compare the first node with mid node and so on until mid==NULL
        ListNode *start = head, *mid = slow->next;
        while(mid != NULL){
            if(start->val != mid->val) return false;
            start = start->next;
            mid = mid->next;
        }
        
        // since we modified/reversed the LL from mid node we have to make it normal again as we should not change input data
        slow->next = reverseList(slow->next);
        return true;
    }
};
