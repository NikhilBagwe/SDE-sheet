## > BRUTE ======= TC = O(n - traversal) + O(nlogn - sorting) , SC = O(n)

- Do simple Inorder traversal and pass an array
- Store all the node values into it
- Then sort the array and return the kth element

```cpp

class Solution {
public:
    void traverse(TreeNode* root, vector<int> &inorder){
        if(root == NULL){
            return;
        }
        traverse(root->left, inorder);
        inorder.push_back(root->val);
        traverse(root->right, inorder);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inorder;
        traverse(root, inorder);
        sort(inorder.begin(), inorder.end());
        return inorder[k-1];
    }
};
```
