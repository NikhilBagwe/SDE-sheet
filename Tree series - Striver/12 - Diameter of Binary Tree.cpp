// BRUTE ============================================== TC = O(n^2)  ========================================================================================

// TC = O(n^2) -> Traversing the whole tree takes O(n) and calculating height of each subtree takes O(n)
class Solution {
public:
    // Finds height of the given subtree
    int height(TreeNode *node){
        if(node == NULL) return 0;
        
        int lh = height(node->left);
        int rh = height(node->right);
        
        return 1 + max(lh, rh);
    }
    
    // Stores the maximum diameter of tree
    int maxi = 0;
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        // Calculate the heights of left and right subtree
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        
        // compare the current maxi with the addition of left and right subtree i.e the diameter and update maxi with the maximum diameter
        maxi = max(maxi, leftHeight+rightHeight);
        
        // Call recursion on left and right child nodes
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return maxi;
    }
};

// OPTIMAL ============================================== TC = O(n) , SC = O(n) ========================================================================================

// Instead of calculating the height separately we are calculating the height and updating the diameter together

class Solution {
public:
    // Finds height of the given subtree -> modified a bit to calculate the diameter at the same time
    int height(TreeNode *node, int& diameter){
        if(node == NULL) return 0;
        
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        
        diameter = max(diameter, lh+rh);
        
        return 1 + max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};
