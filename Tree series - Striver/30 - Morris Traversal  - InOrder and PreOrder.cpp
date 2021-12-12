// ========== INORDER ================================================ TC = O(N) , SC = O(1) ==============================================================

// TC = O(N) -> it is amortized time complexity i.e addition of O(N)+O(N)+O(N) ~ O(N)

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        
        // Inorder - Morris traversal
        while(cur != NULL){
            // 1st case - If left child is null, it means you are standing on root, so print it and move to right
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            
            // 2nd case - when left child exists, go to the rightmost node of the left subtree 
            else{
                TreeNode* prev = cur->left;
                // Keep going right until it's not null and it dosen't points to itself
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                // Create the thread pointing to current node and then move cur to left
                if(prev->right == NULL){
                    prev->right = cur;
                    cur = cur->left;
                }
                
                // 3rd case - If thread exists i.e 'prev->right' points back to itself, remove the thread
                else{
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        return inorder;
    }
};

// ========== PREORDER ====================================== Just a one line change in 2nd case =============================================================

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* cur = root;
        
        while(cur != NULL){
            if(cur->left == NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            
            else{
                TreeNode* prev = cur->left;
                while(prev->right && prev->right != cur){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = cur;
                    inorder.push_back(cur->val);  // CHANGE -> You are curently standing on the root so print it
                    cur = cur->left;
                }
                
                else{
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        
        return inorder;
    }
};


