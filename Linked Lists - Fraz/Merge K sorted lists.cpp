// BRUTE ============== Pick the first 2 LL, then merge them and store them separately, then take the next LL and merge it with the already sorted LL

// OPTIMAL ================================================= TC = NlogK , SC = O(k) ===================================================================================

// TC = NlogK -> It takes 'O(logk)' time to insert/pop elements into min-heap where k=size of min-heap. N is the total number of nodes in the list.
// SC = O(k) -> As we storing only the heads of all 'k' lists.

class cmp{
    public:
    
    bool operator() (ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min heap storing heads of all the lists
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
      
        // Dummy node to act as the starting of LL
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        
        // Push 'heads' of all lists into min-heap
        for(int i=0; i<lists.size(); i++){
            if(lists[i] != NULL){
                q.push(lists[i]);
            }
        }
        
        // Until the queue becomes empty, pick up the smallest element stored at top of the queue and also 'delete' it, and also insert the next element after temp.
        while(q.size()){
            ListNode *temp = q.top();
            tail->next = temp;
            tail = temp;
            q.pop();
            if(temp->next != NULL) q.push(temp->next);
        }
        
        return dummy->next;
    }
};
