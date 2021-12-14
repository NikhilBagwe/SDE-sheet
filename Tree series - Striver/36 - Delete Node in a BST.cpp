// ============================================================ TC = O(Height of tree) ====================================================

/*
- Search where the node is present in BST
- Then delete it using any one method:
1. Stand on the node to be deleted. Now connect the parent node of node to be deleted with it's left subtree and then attach the right subtree to the
   rightmost node of the left subtree.
2. Vice versa for right subtree
*/

class Solution {
public:
    // Finds the rightmost node of given tree
    TreeNode* findLastRight(TreeNode* root){
        while(root->right != NULL){
            root = root->right;
        }
        return root;
    }
    
    // Does the necessary connections after deleteing the node
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        
        // Store the RST
        TreeNode* rightChild = root->right;
        // Store the Rightmost node of LST
        TreeNode* lastRight = findLastRight(root->left);
        // Attach the RST to LST's rightmost node
        lastRight->right = rightChild;
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;
        
        if(root->val == key){
            return helper(root);
        }
        
        TreeNode* dummy = root;
        
        while(root != NULL){
            // Keep going LEFT if current node's value is greater than key
            if(root->val > key){
                // Check if the current node's, left node is the node to be deleted or not
                if(root->left != NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                // Go to next left node
                else{
                    root = root->left;
                }
            }
            
            // Keep going RIGHT if current node's value is smaller than key
            else{
                // Check if the current node's, right node is the node to be deleted or not
                if(root->right != NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        
        return dummy;
    }
};
