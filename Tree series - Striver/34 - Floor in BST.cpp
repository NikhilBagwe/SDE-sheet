// You are given a BST (Binary search tree) with’ N’ number of nodes and a value ‘X’. 
// Your task is to find the greatest value node of the BST which is smaller than or equal to ‘X’.

int floorInBST(TreeNode<int> * root, int x)
{
    int ans = -1;
    while(root){
        // If you find the same value as 'x', return it as it will be the greatest value node of the BST  which is smaller than or equal to 'x'
        if(root->val == x){
            ans = root->val;
            return ans;
        }
        
        if(root->val > x) root = root->left;
        else{
            ans = root->val;
            root = root->right;
        }
    }
    return ans;
}
