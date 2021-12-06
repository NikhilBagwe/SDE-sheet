// ========================================== TC = O(n) , SC = O(height of tree) ======================================================================

bool pathToNode(TreeNode* node, int val, vector<int> &ans){
    // When you reach a leaf node return false 
    if(!node) return false;

    ans.push_back(node->val);

    if(node->val == val){
        return true;
    }

    // Perform DFS traversal - IF any one of the below returns true, means we found the path to the given node
    if(pathToNode(node->left, val, ans) || pathToNode(node->right, val, ans)){
        return true;
    }

    ans.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode* root, int val) {
    vector<int> ans;
    if(root == NULL) return ans;

    pathToNode(root, val, ans);
    return ans;
}
