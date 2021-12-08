// ==================== TC = O(n-markParents traversal) + O(n-traversing tree radially from target) + O(logn-for hashmap) = O(nlogn)
// ==================== SC = O(n-parent_track) + O(n-visited) + O(n-queue) = O(n) 

/*
- Mark each node to its parent to traverse upwards
- We will do a BFS traversal starting from the target node
- As long as we have not seen our node previously, Traverse up, left, right until reached Kth distance
- when reached Kth distance, break out of BFS loop and remaining node's values in our queue is our result
*/

class Solution {
public:
    // Simple level order traversal - To mark each node to its parent to traverse upwards
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left){
                // Store the parent pointer pair where "node->left" is the child and "node" is the parent
                parent_track[node->left] = node;
                q.push(node->left);
            }
            
            if(node->right){
                // Store the parent pointer pair where "node->right" is the child and "node" is the parent
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // Store parent pointer pairs(pair of a node and its root node) in map as : map<child node, parent/root node>
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, target);
        
        // Traversing radially in all directions from the target node
        unordered_map<TreeNode*, bool> visited; // Keep a track of how many nodes we visited
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        
        // Stores the current kth distance we travelled from the target level-wise
        int curr_level = 0;
        
        while(!q.empty()){
            int size = q.size();
            // If curr_level becomes equal to 'k' break or else increase it by 1
            if(curr_level++ == k) break;
            
            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
                
                // Traverse for the left and right child nodes
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                
                // Traverse upwards to root node
                if(parent_track[node] && !visited[parent_track[node]]){
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
        
        vector<int> result;
        // The nodes remaining in the queue is your answer
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            result.push_back(temp->val);
        }
        
        return result;
    }
};
