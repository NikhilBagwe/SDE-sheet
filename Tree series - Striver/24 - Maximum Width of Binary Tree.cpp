// ====================================================== TC = SC = O(n) ========================================================================================

// TC = O(n) -> Since we are doing a level order traversal
// SC = O(n) -> For queue ds

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int maxWidth = 0;
        if(!root) return maxWidth;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int size = q.size();
            // Stores the minimum index on the level
            int minIndex = q.front().second;
            
            int first, last;
            for(int i=0; i<size; i++){
                // To avoid overflow error - store the indexes on every level, starting from 0, then 1 and so on
                int curIndex = q.front().second - minIndex;
                
                TreeNode* node = q.front().first;
                q.pop();
                
                // Store the first and last node on the current level
                if(i == 0) first = curIndex;
                if(i == size-1) last = curIndex;
                
                // Refer notes for formulas ---------------------------------------------------------------------------------------------
                if(node->left) q.push({node->left, curIndex*2 + 1});
                if(node->right) q.push({node->right, curIndex*2 + 2});
            }
            maxWidth = max(maxWidth, last-first+1);
        }
        
        return maxWidth;
    }
};

