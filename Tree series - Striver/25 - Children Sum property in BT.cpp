// BRUTE ================================= O(n^2) ---- Refer GFG =======================================================


// OPTIMAL =========================================================== TC = O(n) , SC = O(H) =======================================================================

/*
- Here we take major advantage of the fact that we can increase the node's data value by '1' any number of times, but we can't reduce it.

- The idea is that, we start from the root node and add up the data of child nodes and store it in 'child' then compare it with root node's data. If the 'child'
  data is less than root's data than we assign the root's data to both child nodes and we do so on for the rest nodes also.
  
- After reaching the leaf nodes, while backtracking we start assigning the addition of left and right child nodes data to there root node, thus making a tree following child 
  sum property.
*/

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
