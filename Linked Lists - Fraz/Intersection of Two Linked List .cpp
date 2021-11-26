// BRUTE =========================================== TC = O(n) =========================================================================================

/*
- Calculate the length of both LL
- Move the 'head' of LL whose length is more by 'k', so that both LL become of same length
- Now start traversing both LL and keep comparing their nodes until you reach the Intersection point which will be same for both LL
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
        
        ListNode *temp = headA;
        int n1 = 0, n2 =0;
        
        // Calculate length of both LL
        while(temp != NULL){
            n1++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL){
            n2++;
            temp = temp->next;
        }
        
        int k = 0;
        if(n1 > n2) k = n1-n2;
        else if(n1 < n2) k = n2-n1;
        
        // Move the LL with greater size by 'k'
        while(k--){
            if(n1 > n2) headA = headA->next;
            if(n1 < n2) headB = headB->next;
        }
        
        // Find the intersection point
        ListNode *ptr1 = headA, *ptr2 = headB;
        while(ptr1 != ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
};
