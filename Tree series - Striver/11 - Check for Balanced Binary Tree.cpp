// ============================= TC = O(n^2) -- We find height/depth of tree takes O(n) and another O(n) for traversal ===========================================

class Solution {
public:
    // Finds height/depth of the given tree
    int height(TreeNode *node){
        if(node == NULL) return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        
        return 1+max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        // Find the height of left and right subtree of given root node
        int left = height(root->left);
        int right = height(root->right);
        
        // If the difference between their heights is more than 1, than directly return false
        if(abs(left-right) > 1) return false;
        
        // Go to the next left and right nodes and check for their subtrees whether they are balanced or not
        bool leftNode = isBalanced(root->left);
        bool rightNode = isBalanced(root->right);
        
        if(!rightNode || !leftNode) return false;
        else return true;
    }
};

// ========================= TC = O(n) -- as its a recurssive traversal , SC = O(n) -- worst case for skewed tree the auxilary stack space is O(n) ======================

/*
- If at any point, the height function returns a '-1', means the given tree is not a balanced tree.
- Refer recurssive tree from notes
*/

class Solution {
public:
    // Finds height of the given tree
    int height(TreeNode *node){
        if(node == NULL) return 0;
        
        int lh = height(node->left);
        if(lh == -1) return -1;
        
        int rh = height(node->right);
        if(rh == -1) return -1;
        
        if(abs(lh - rh) > 1) return -1;
        
        return 1 + max(lh, rh);
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
