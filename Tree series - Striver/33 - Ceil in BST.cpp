/* 
Ceil of an integer is the closest integer greater than or equal to a given number.
For example:
arr[] = {1, 2, 5, 7, 8, 9}, key = 3.
The closest integer greater than 3 in the given array is 5. So, its ceil value in the given array is 5.
*/

int findCeil(BinaryTreeNode<int> *node, int x){
    int ceil = -1;
    while(node){
        // If you find the same number, directly return the number after storing it into ceil
        if(node->data == x ){
            ceil = node->data;
            return ceil;
        }
        
        // If current node value is small, go towards right in search of even greater value
        if(x > node->data){
            node = node->right;
        }
        // If current node value is greater, store the value and go towards left in search of even smaller or equal value
        else{
            ceil = node->data;
            node = node->left;
        }
    }
    return ceil;
}
