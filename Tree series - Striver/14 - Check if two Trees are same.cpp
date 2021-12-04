// ================================================== TC = O(n) , SC = O(n) =========================================================================

    // You can use any Traversal technique to traverse the tree and here we have used -> PreOrder traversal

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL){
            return (p==q);
        }
        
        // PreOrder traversal -> Root - Left - Right
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
