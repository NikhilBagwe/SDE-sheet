// BRUTE =============================== REVERSE FUNCTION =========================================================================================

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // When leftToRight is 'false' means store elements from left to right into level array, else reverse elements of level array
        bool leftToRight = false;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
            for(int i=0; i<size; i++){
                TreeNode *temp = q.front();
                q.pop();
                
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                
                level.push_back(temp->val);
            }
            
            // Zig-Zag logic ->
            // If 'leftToRight' = true, then reverse 'level' array and then store it into result array. 
            // If 'leftToRight' = false, store the array directly into the 'result' array.
            if(leftToRight){
                reverse(level.begin(), level.end());
            }
            result.push_back(level);
            
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

// OPTIMAL ================================= WITHOUT USING REVERSE FUNCTION ==== TC = O(N) , SC = O(N) ======================================================

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == NULL) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        // When leftToRight is 'true' means store elements from left to right into level array, else reverse elements of level array
        bool leftToRight = true;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);
            
            for(int i=0; i<size; i++){
                TreeNode *temp = q.front();
                q.pop();
                
                // Find the position to fill the node's value into 'level' array i.e either insert from front or from end
                int index = (leftToRight) ? i : size-1-i;
                level[index] = temp->val;
                    
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            
            
            result.push_back(level);
            
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};

