// BRUTE ====================================== RECURSION ============== TC = O(n+m) , SC = O(n+m) ================================================================

// TC = O(n+m) -> where 'n' and 'm' are the number of nodes present in each LL respectively

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2){
        // BASE CASE - check whether any of the given list is empty or not and return the LL which has elements
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        // If value stored in l1 is smaller than value in l2
        if(l1->val < l2->val){
            // Keep 'l1' node and Pass the remaining LL i.e except l1 pass everything after 'l1' i.e 'l1->next' and the whole 'l2' list
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        return merge(l1, l2);
    }
};

// OPTIMAL ====================================== ITERATIVE ============== TC = O(n+m) , SC = O(1) ================================================================

class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        // 'head' of our merged list will be stored in 'ans' and 'tail' will keep a track of our end node
        ListNode *ans, *tail;
        
        // Find the 1st smallest node and store it into 'ans' as head node
        if(l1->val < l2->val){
            ans = l1;
            tail = l1;
            l1 = l1->next;
        }
        else{
            ans = l2;
            tail = l2;
            l2 = l2->next;
        }
        
        // Keep attaching nodes to the 'tail' node based on their 'values'
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                tail->next = l1;
                // Move to next node
                tail = l1;
                l1 = l1->next;
            }
            else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        // If in case any of the list still remains attach it directly to the end of merged list
        if(l1 == NULL) tail->next = l2;
        else tail->next = l1;
        
        return ans;
    }
};

// ============================= USE DUMMY NODE AND ELIMINATE IF-ELSE conditions AT LINE 41 ===================================================================

class Solution {
public:
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        // Init a dummy node pointing to start of merged LL
        ListNode *ans = new ListNode(-1);
        ListNode *tail = ans;
        
        while(l1 != NULL && l2 != NULL){
            
            if(l1->val < l2->val){
                tail->next = l1;
                tail = l1;
                l1 = l1->next;
            }
            
            else{
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }
        
        if(l1 == NULL) tail->next = l2;
        else tail->next = l1;
        
        // as 'ans' is pointing to head, return the 'next' of ans as the head node
        return ans->next;
    }
};
