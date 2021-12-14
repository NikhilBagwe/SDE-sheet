// ===================================================== TC = O(logn) ===============================================================================

/*
- It is guaranteed that the new value to be inserted does not exist in the original BST.
- Traverse the tree and find at which leaf position the node can be inserted
- Instead of inserting anywhere in middle and changing the structure of tree, it's better to insert at leaf node
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If root is null, instead of root create a new node with given 'val' and return it
        if(root == NULL) return new TreeNode(val);
        
        TreeNode* cur = root;
        while(true){
            if(cur->val <= val){
                // Keep going towards right until you reach the leaf node
                if(cur->right != NULL) cur = cur->right;
                // When you reach leaf node i.e (cur->right becomes NULL), insert the new node
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            
            else{
                // Keep going towards left until you reach the leaf node
                if(cur->left != NULL) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};
