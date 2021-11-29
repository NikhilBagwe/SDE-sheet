// =============================================== TC = SC = O(n) ==================================================================================

// SC = O(n) --- Suppose there is a skewed tree having only left nodes, then you will end up pushing all nodes into the stack OR the height of binary tree

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node = root;
        
        while(true){
            // Until node becomes NULL keep going to left of the tree and keep pushing the nodes into stack  
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            
            else{
                if(st.empty()) break;
                // The topmost node in stack will be our root node so we have to print it
                node = st.top();
                st.pop();
                // print/push the root node, and then move to right child node of current node
                ans.push_back(node->val);
                node = node->right;
            }
        }
        return ans;
    }
};
