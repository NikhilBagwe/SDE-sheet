// =============================== TC = O(nlogn) (for multiset - logn) , SC = O(n) ================================================================================

vector<vector<int>> verticalOrderTraversal(TreeNode<int> *root)
{
    // Map to store the Vertical order traversal as follows: We use a multiset to store similar node values as it is possoble that multiple nodes might be
    // present at the same position
    // map<vertical line no. <level no. , values of nodes present at that level on that line>>
    map<int, map<int, multiset<int>>> nodes;
    // In Queue we are storing the node and pair of 'vertical line no.' and level number
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        // Store the node
        TreeNode<int> *node = it.first;
        // Store the vertical line and level number respectively
        int line = it.second.first, level = it.second.second;
        
        // insert the node value into map
        nodes[line][level].insert(node->data);
        
        // Since we are always going downwards, do level+1 and as per the left or right node add or minus '1' from line
        if(node->left) q.push({node->left, {line-1, level+1}});
        if(node->right) q.push({node->right, {line+1, level+1}});
    }
  
    vector<vector<int>> ans;
    for(auto it : nodes){ // it stores -> map<int, map<int, multiset<int>>>
        // Stores all the nodes corresponding to a vertical line
        vector<int> col;
      
        for(auto p : it.second){ // p stores -> map<int, multiset<int>
            col.insert(col.end(), p.second.begin(), p.second.end());
        }
      
        ans.push_back(col);
    }
    
    return ans;
}
