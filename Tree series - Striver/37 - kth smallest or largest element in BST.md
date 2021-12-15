## > BRUTE ======= TC = O(n - traversal) + O(nlogn - sorting) , SC = O(n)

- Do simple Preorder or any DFS traversal and pass an array with it.
- Store all the node values into it
- Then sort the array and return the kth element

```cpp

class Solution {
public:
    void traverse(TreeNode* root, vector<int> &preorder){
        if(root == NULL){
            return;
        }
        preorder.push_back(root->val);
        traverse(root->left, preorder);
        traverse(root->right, preorder);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> preorder;
        traverse(root, preorder);
        sort(preorder.begin(), preorder.end());
        return preorder[k-1];
    }
};
```
## > OPTIMAL ======= TC = O(n) , SC = O(n)

- In case of BST, the Inorder traveral by default gives us the array in sorted order due to property of BST i.e smaller elements are present on left of root node and higher on right.
- So here we will add a counter to keep a track of which node we are currently on and when counter becomes equal to 'k' return the current node's value as answer.
- We can do the same for Morris traversal also giving SC = O(1)

```cpp
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        stack<TreeNode*> st;
        int count = 0;
        
        // Inorder traversal
        while(true){
            if(node != NULL){
                st.push(node);
                node = node->left;
            }
            
            else{
                if(st.empty() == true) break;
                node = st.top();
                st.pop();
                count++;
                // Print/storing the value is not required as we have counter so we check if (count == k)
                and return node->val or pass the node towards right as per inorder traversal method
                if(count == k) return node->val;
                node = node->right;
            }
        }
        
        return -1;
    }
};
```

## > To find kth Largest element :

- You need to do 2 traversals 
- First to calculate the 'N' no. of nodes in tree
- Second traversal to find the N-kth element which will be our kth largest element.
- 
