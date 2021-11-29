// Left - Right - Root

void postOrder(Node *root){
    // When reaches a leaf node 
    if(root == NULL){
        return;
    }
    
    // Pass recursion to left
    postOrder(root->left);
    // Pass recursion to right
    postOrder(root->right);
    // Print the root node 
    print(root->data);
}
