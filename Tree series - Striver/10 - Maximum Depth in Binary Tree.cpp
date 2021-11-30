// =================================== TC = O(n) -> as we go to each node, SC = O(n) -> in worst case of skewed tree ====================================================

/*
- While standing on the root node, calculate the height of left subtree and right subtree and find out the maximum out of them and and 1 to it.
*/

class Solution {
public:
    
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        
        return 1 + max(leftHeight, rightHeight);
    }
};
