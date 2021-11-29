
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        
        // Create a queue and push the root node into it
        queue<TreeNode*> q;
        q.push(root);
        
        // Iterate until queue becomes empty
        while(!q.empty()){
            // stores the values of nodes level-wise
            vector<int> level;
            int size = q.size();
            
            for(int i=0; i<size; i++){
                // Store the topmost node from queue into temp node and pop it from queue
                TreeNode *temp = q.front();
                q.pop();
                
                // Push the temp node's children into the queue and store it's value into level ds
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};
