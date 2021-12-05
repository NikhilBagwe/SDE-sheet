// ==================================================== TC = SC = O(n) ====================================================================================

/*
- By symmetrical we mean 'Mirror' image means left is looking to right and vice versa.
- So here we will perform a normal traversal on left subtree and reverse traversal on right subtree so that symmetric condition are met.
- Traverse both subtrees simultaneously.
*/

class Solution {
public:
    bool symmetric(TreeNode* left, TreeNode* right){
        // If anyone of the node becomes NULL, the other has to be NULL
        if(left == NULL || right == NULL){
            return left==right;
        }
        
        if(left->val != right->val) return false;
        
        // Traverse symmetrically 
        return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL || symmetric(root->left, root->right);
    }
};
