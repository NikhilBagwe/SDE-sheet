// CodeStudio solution so -> TreeNode<int>* = TreeNode*
// TC = SC = O(n)

bool isLeaf(TreeNode<int>* node){
    return !node->left && !node->right;
}

// This function will only add nodes present on the left boundary excluding leaf nodes
void addLeftBoundary(TreeNode<int>* node, vector<int> &ans){
    TreeNode<int>* cur = node->left;
  
    while(cur){
        // if 'cur' is not a leaf node than only we will add it into ans
        if(!isLeaf(cur)) ans.push_back(cur->data);
        // then move to the left or else move to the right
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
}

// Right boundary - Here we have to store the nodes stored in 'temp' in reverse order inside 'ans'
void addRightBoundary(TreeNode<int>* node, vector<int> &ans){
    TreeNode<int>* cur = node->right;
    vector<int> temp;
  
    while(cur){
        // if 'cur' is not a leaf node than only we will add it into ans
        if(!isLeaf(cur)) temp.push_back(cur->data);
        // then move to the right or else move to the left
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
  
    for(int i = temp.size()-1; i >= 0; --i){
        ans.push_back(temp[i]);
    }
}

// Perform simple inorder traversal
void addLeaves(TreeNode<int>* node, vector<int> &ans){
    // Check if it's a root element, than only add it to 'ans'
    if(isLeaf(node)){
        ans.push_back(node->data);
        return; 
    }
    
    if(node->left) addLeaves(node->left, ans);
    if(node->right) addLeaves(node->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    // check if the root node is not a leaf node and then add it into the 'ans'
    if(!isLeaf(root)) ans.push_back(root->data);
    
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    
    return ans;
}
