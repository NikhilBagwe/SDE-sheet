// ================================================= TC = SC = O(n) =================================================================================

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // Init a stack and push the root node into it
        stack<TreeNode*> s;
        s.push(root); 
        
        while(!s.empty()){
            TreeNode* temp = s.top();
            s.pop();
            
            // Always first insert the right node first, then the left node into the stack as we have to first go to the left node as per the convention of preorder traversal so
            // left node will be at the top of the stack
            if(temp->right != NULL) s.push(temp->right);
            if(temp->left != NULL) s.push(temp->left);
          
            ans.push_back(temp->val);
        }
        return ans;
    }
};
