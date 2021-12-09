// ==== TC = O(logn-for traversal) * O(logn-for calculating height) = O(logn^2) 
// ==== SC = O(logn - height of tree)

/*
- Whenever we visit a node we calculate it left and right height and if both heights are same i.e perfect tree we apply the formula to calculate the total no. of nodes in
  that tree and return them directly.
  Formula : 2 ^ height of tree - 1
  
- If right and left subtree height are not same,  we go on left and right subtree and again determine if they are perfect tree.
- When we have our left and right heights, we do (1 + left + right)
- If we reach null, return 0
*/

class Solution {
public:
    // Finds height of left subtree
    int findLeftHeight(TreeNode* node){
        int height = 0;
        
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }
    
    // Finds height of right subtree
    int findRightHeight(TreeNode* node){
        int height = 0;
        
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int leftHeight = findLeftHeight(root);
        int rightHeight = findRightHeight(root);
        
        // If both heights are same, apply the formula and return total nodes
        if(leftHeight == rightHeight) return (1 << rightHeight) - 1; // or pow(2, rightHeight)
        
        // Else pass the child nodes into recursion to find a perfect tree and add '1' while returning as we consider the current node also in the total nodes
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
