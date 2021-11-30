/*
- Create a stack to store pairs of node and number.
- Push the root node and num=1 into it as initial configuration.

- Take the topmost element from the stack and store into a variable say 'it'.
  1. If the number stored in pair 'it' i.e it.second is '1', then push the value of it's node into "Pre-order traversal" storing vector also push the node back into stack 
     by incrementing it's value by 1 and if it has a left child, then push it into the stack.
     
  2. If the number stored in pair 'it' i.e it.second is '2', then push the value of it's node into "In-order traversal" storing vector also push the node back into stack 
     by incrementing it's value by 1 and if it has a right child, then push it into the stack. 
     
  3. If the number stored in pair 'it' i.e it.second is '3', then push the value of it's node into "Post-order traversal" storing vector and don't push anything.
*/

class Solution {

public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> st; 
        st.push({root, 1}); 
        vector<int> pre, in, post;
        if(root == NULL) return post;

        while(!st.empty()) {
            auto it = st.top(); 
            st.pop(); 

            // this is part of pre-order traversal
            // increment 1 to 2 
            // push the left side of the tree
            if(it.second == 1) {
                pre.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->left != NULL) {
                    st.push({it.first->left, 1}); 
                }
            }

            // this is a part of in order
            // increment 2 to 3 
            // push right 
            else if(it.second == 2) {
                in.push_back(it.first->val); 
                it.second++; 
                st.push(it); 

                if(it.first->right != NULL) {
                    st.push({it.first->right, 1}); 
                }
            }
            // don't push it back again 
            else {
                post.push_back(it.first->val); 
            }
        } 

        return post; 
    }
};
