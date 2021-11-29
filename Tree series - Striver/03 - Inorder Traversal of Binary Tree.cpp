
void inorder(Node *root){
    // When reaches a leaf node 
    if(root == NULL){
        return;
    }
    
    // Pass recursion to left
    inorder(root->left);
    // Print the root node 
    print(root->data);
    // Pass recursion to right
    inorder(root->right);
}
