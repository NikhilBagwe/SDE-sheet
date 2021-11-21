// Write a function to delete a node in a singly-linked list. You will not be given access to the head of the list, instead you will be given access to the node to be deleted 
// directly. It is guaranteed that the node to be deleted is not a tail node in the list.

It is guaranteed that the node to be deleted is not a tail node in the list.

class Solution {
public:
    void deleteNode(ListNode* node) {
        // Check if you are standing on the Last/tail node
        if(node->next == NULL) delete node;
        
        // Swap the values of current node(i.e the node to be deleted) with the next node
        // eg: 1->2->3->4  we have to delete 3. So swap node 3 with 4
        // On swapping = 1 2 4 3
        swap(node->val, node->next->val);
      
        // Store the next node in a variable
        ListNode* temp = node->next;
        // Assign the current node i.e node 4's next with node 3's next which is going to be deleted
        node->next = node->next->next;
        // Delete to avoid memory leakage
        delete temp;
    }
};
