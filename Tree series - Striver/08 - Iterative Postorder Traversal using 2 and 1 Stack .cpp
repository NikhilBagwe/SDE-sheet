// ================= USING 2 STACKS ================================ TC = O(n) , SC = O(2n) -- as we are using 2 stacks ================================================

/*
- Init 2 stacks and push the root node into stack 1 as your initial configuration.
- Now pop a node from stack 1, push it into stack 2 and if the popped node has any children i.e left and right, then push them into stack 1
- Keep doing the above, until stack 1 becomes empty.
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // Init two stacks and push the 'root' node into the first stack
        stack<TreeNode*> s1, s2;
        TreeNode *node = root;
        s1.push(root);
        
        // Loop until stack 1 is empty
        while(!s1.empty()){
            // Take out the topmost node from stack 1 and push it into stack 2
            TreeNode *node = s1.top();
            s2.push(node);
            s1.pop();
            
            // Push the left and right children of the topmost node i.e 'node' into stack 1 if they are not NULL
            if(node->left != NULL) s1.push(node->left);
            if(node->right != NULL) s1.push(node->right);
        }
        
        // Since, stack 2 will contain the post-order traversal, put it into 'ans'
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};
