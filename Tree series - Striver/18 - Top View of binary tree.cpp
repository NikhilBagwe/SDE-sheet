// Code studio = https://www.codingninjas.com/codestudio/problems/top-view-of-the-tree

/*
- We will divide the tree using vertical lines and the line going through root node will be 0
- The line before root node is '-1' and line after is '+1' and so on
- Init a queue ds and put the root node into it.
- Now keep looping until queue becomes empty - pop the topmost pair stored in queue, check whether the 'line' number is inserted into the map or not, then insert it, and
  then push the child node into queue with their line number respectively
*/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    
    // Map stores the vertical line no. and its corresponding first node from top view
    map<int, int> mp;
    queue<pair<TreeNode<int>*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        // Pick the top 'pair' from queue and then pop it
        auto it = q.front();
        q.pop();
        TreeNode<int> *node = it.first;
        int line = it.second;
        
        // If the line is not present in the map then insert it with it's corresponding node
        if(mp.find(line) == mp.end()) mp[line] = node->val;
        
        // Now put the child nodes into the queue
        // If its a left node then do 'line-1'
        if(node->left != NULL) q.push({node->left, line-1});
      
        // If its a right node then do 'line+1'
        if(node->right != NULL) q.push({node->right, line+1});
    }
  
    for(auto it : mp){
        ans.push_back(it.second);
    }
    
    return ans;
}
