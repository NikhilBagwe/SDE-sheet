// ========================= Recurssive ========================== TC = O(n) , SC = O(n) - stack space ==========================================================

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        // Traverse to the right as much as possible
        flatten(root->right);
        flatten(root->left);
        
        // Logic to convert the tree into a Linked list. LL is formed as right-sided i.e no node has a left child
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// ======================== Iterative ========================== TC = O(n) , SC = O(n) ==========================================================================

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* cur = st.top();
            st.pop();
            
            // Push the right child node first and then left into stack
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
            
            // As we pushed left node after right node into stack, so it left node will be present at top in the stack. Assign it as the new right node to current node
            if(!st.empty()){
                cur->right = st.top();
            }
            
            // Make left node null for all nodes - as we are forming LL only of right nodes
            cur->left = NULL;
        }
    }
};

// ======================== Morris Traversal ======================= TC = O(n) , SC = O(1) ==========================================================================

/*
- We will connect the rightmost node of the left subtree to the root's right node by a thread and will do the same for all subtrees
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        
        // Point cur to the root node
        TreeNode* cur = root;
        
        while(cur){
            // check if cur has a left node
            if(cur->left){
                // Store cur->left
                TreeNode* prev = cur->left;
                
                // Traverse to the rightmost node of left subtree
                while(prev->right){
                    prev = prev->right;
                }
                
                // Create connection between the rightmost node(prev) and root's(cur) right node
                prev->right = cur->right;
                // Point 'cur's right to cur's left
                cur->right = cur->left;
                cur->left = NULL;
            }
            // Move to next right node of cur
            cur = cur->right;
        }
    }
};
