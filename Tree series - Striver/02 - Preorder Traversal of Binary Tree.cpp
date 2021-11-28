// ====================== TC = O(n) , where n = no. of nodes , SC = O(n) i.e the height of the tree ===========================================================

// Root - Left - Right 

void preOrder(Node *root){
    if(root == NULL){
        return;
    }
    
    // Print the root node 
    print(root->data);
    // Send recursion to left node
    preOrder(root->left);
    // Send recursion to right node 
    preOrder(root->right);
}
