/*
- For overlapping nodes, take the right most node into final answer
- The logic is same as Top view of binary tree problem, but the only thing we do here is that we keep updating the nodes corressponding to line number in the map 
  until we reach the last node as we want the bottom view.

== NOTE : We can also implement the same iterative code using recursion, but we have to keep track of height or else we will end up storing wrong node

*/

vector<int> bottomView(BinaryTreeNode<int> * root){
    vector<int> ans;
    if(root == NULL) return ans;
    
    queue<pair<BinaryTreeNode<int>*, int>> q;
    // Map store data in ascending/sorted order unlike unordered_map
    map<int, int> mp;
    q.push({root, 0});
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        BinaryTreeNode<int> *node = it.first;
        int line = it.second;
        
        // Update the node value until we reach the last node
        mp[line] = node->data;
        
        if(node->left != NULL) q.push({node->left, line-1});
        if(node->right != NULL) q.push({node->right, line+1});
    }
    
    for(auto it : mp){
        ans.push_back(it.second);
    }
    
    return ans;
}
