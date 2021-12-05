// ================================================ TC = O(n) , SC = O(height of binary tree) ===========================================================

/*
- We will use Reverse PreOrder traversal -> Root - Right - Left , where we will go to right node first then to left,  because the every right node we get 
  on traversing will be part of our right view traversal
  
- We will go to each level, add the right most node into a ds only when the "size of ds = current level number".
- The above mentioned condition helps us to keep a track of how many levels we have traversed and inserted their rightmost nodes so that we don't insert a wrong 
  node on the same level again
  
= NOTE : For 'LEFT' view of binary tree just do normal traversal which goes to left node first and then right.

*/

class Solution {
public:
    void rightSide(TreeNode *node, int level, vector<int> &ans){
        if(node == NULL) return;
        
        // If the level number and size of 'ans' is same then only add node value to 'ans' as it will be the rightmost node in that level
         if(level == ans.size()){
            ans.push_back(node->val);
        }
        
        // Reverse PreOrder traversal
        rightSide(node->right, level+1, ans);
        rightSide(node->left, level+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightSide(root, 0, ans);
        return ans;
    }
};
