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
