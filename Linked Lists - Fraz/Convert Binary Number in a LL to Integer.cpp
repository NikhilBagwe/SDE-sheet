// OPTIMAL ================================================================================================================================

/*
In this approach, we consider we are standing on the tail node. And using while loop we check is there a next node available, and if there is one, we consider the next node
to be the tail node and thus we multiple the ans by 2 everytime and also add the current value of the node to it.
*/

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode *temp = head;
        int ans = 0;
        
        while(temp != NULL){
            ans *= 2;
            ans += (temp->val);
            temp = temp->next;
        }
        
        return ans;
    }
};
