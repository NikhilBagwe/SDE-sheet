// =========== CODE ============================================ TC = O(logn) ====================================================================================

// TC = O(logn) -> as we are traversing nearly around height of the tree, which is always 'logn' , thus we don't traverse all nodes and TC = height of the tree i.e logn

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            // When current node's value is greater than 'val' -> Go to LEFT
            if(root->val > val){
                root = root->left;
            }
          
            // Go to RIGHT
            else{
                root = root->right;
            }
        }
        return root;
    }
};

// ================= CLEAN CODE =======================================================================================================

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root->val != val){
            root = root->val > val ? root->left : root->right;
        }
        return root;
    }
};
