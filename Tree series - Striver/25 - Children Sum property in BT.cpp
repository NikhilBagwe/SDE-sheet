// BRUTE ================================= O(n^2) ---- Refer GFG =======================================================


// OPTIMAL =========================================================== TC = O(n) , SC = O(H) =======================================================================

void changeTree(BinaryTreeNode < int > * root) {
    if(root == NULL) return;
    
    // Store the addition of left and right child nodes of current root node into 'child'
    int child = 0;
    if(root->left){
        child += root->left->data;
    }
    if(root->right){
        child += root->right->data;
    }
    
    // If 'child' value is greater than or equal to value stored in root, then change root's value equal to child's va;ue
    if(child >= root->data) root->data = child;
    // If 'child' value is less than root's value, then change both left and right child nodes value equal to root's value
    else{
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    
    // Traversal 
    changeTree(root->left);
    changeTree(root->right);
    
    // while backtracking, take sum of left and right nodes and assign it to root node
    int total = 0;
    if(root->left) total += root->left->data;
    if(root->right) total += root->right->data;
    // Update only if the current root node is not a leaf node
    if(root->left || root->right) root->data = total;
}  
