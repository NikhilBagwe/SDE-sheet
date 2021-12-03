// We will go to each node, calculate its maximum path sum and accordingly keep updating maxi

class Solution {
public:
    int maxPathSumAtNode(TreeNode* node, int& maxi){
        if(node == NULL) return 0;
        
        // Go to right and left child nodes of the current root node and calculate max path sum of them
        // If the left or right node max path sum returns a negative, don't consider it. That's why we pass a 0
        int leftSum = max(0, maxPathSumAtNode(node->left, maxi));
        int rightSum = max(0, maxPathSumAtNode(node->right, maxi));
        
        maxi = max(maxi, leftSum + rightSum + node->val);
        
        // Important step to consider whether to take right or left path sum
        return node->val+max(leftSum, rightSum);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSumAtNode(root, maxi);
        return maxi;
    }
};
