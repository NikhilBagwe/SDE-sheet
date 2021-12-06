// BRUTE ============================================ TC = O(n) + O(n) =============================================================================================

class Solution {
public:
    // Returns the path from root node to the given node - refer previous question no. 22
    bool pathToNode(TreeNode* node, int val, vector<TreeNode*> &a){
        if(!node) return false;
        
        a.push_back(node);
        
        if(node->val == val) return true;
        
        if(pathToNode(node->left, val, a) || pathToNode(node->left, val, a)) return true;
        
        a.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> a1, a2;
        if(root == NULL) return root;
        
        pathToNode(root, p->val, a1);
        pathToNode(root, q->val, a2);
        
        // Compares both arrays and when there is a difference in the node value's, that is the LCA node.
        for(int i=0; i<a1.size(); i++){
            if(a1[i]->val == a2[i]->val) continue;
            // The prev node to current node will be LCA
            else return a1[i-1];
        }
        return root;
    }
};

// OPTIMAL =============================================================== TC = SC = O(n) ==========================================================================

/*
- We use dfs traversal.

- We first go to left as much as possible and if we find anyone of 'p or q' node we return the node.
- Same is done for right as well when left traversal is done.

- In case we, NULL from the left and a valid node from right or vice versa, we return the valid node.
- When both left and right are not NULL, we got our LCA.
*/

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case - when current node is same as anyone of 'p' or 'q' nodes or NULL
        if(root == NULL || root == p || root == q){
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // while traversing back, if we get 'NULL' returned from left , then return 'right' node
        if(left == NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        // When both left and right are not NULL , we got our result
        else{
            return root;
        }
    }
};

