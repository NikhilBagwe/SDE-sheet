// ================= USING 2 STACKS ================================ TC = O(n) , SC = O(2n) -- as we are using 2 stacks ================================================

/*
- Init 2 stacks and push the root node into stack 1 as your initial configuration.
- Now pop a node from stack 1, push it into stack 2 and if the popped node has any children i.e left and right, then push them into stack 1
- Keep doing the above, until stack 1 becomes empty.
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // Init two stacks and push the 'root' node into the first stack
        stack<TreeNode*> s1, s2;
        TreeNode *node = root;
        s1.push(root);
        
        // Loop until stack 1 is empty
        while(!s1.empty()){
            // Take out the topmost node from stack 1 and push it into stack 2
            TreeNode *node = s1.top();
            s2.push(node);
            s1.pop();
            
            // Push the left and right children of the topmost node i.e 'node' into stack 1 if they are not NULL
            if(node->left != NULL) s1.push(node->left);
            if(node->right != NULL) s1.push(node->right);
        }
        
        // Since, stack 2 will contain the post-order traversal, put it into 'ans'
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        return ans;
    }
};

// ========================== USING 2 STACKS ================================ TC = O(2n) , SC = O(n) -- as we are using 1 stack ======================================

// TC = O(2n) --- as in the worst case there will be skewed tree having only right nodes. So you end up pushing all of them into stack taking O(n) time and then again
// traversing back using while(!st.empty() && temp == st.top()->right) loop.

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        // Init a stack 
        stack<TreeNode*> st;
        TreeNode *cur = root;
        TreeNode *temp;
        
        while(cur != NULL || !st.empty()){
            // Push the 'cur' node into stack and keep going towards the left of tree until you hit NULL
            if(cur != NULL){
                st.push(cur);
                cur = cur->left;
            }
            
            else{
                // Once left becomes NULL, traverse towards 'right'
                temp = st.top()->right;
                
                // If right is also NULL, means you are standing on a leaf node (which is a 'root' node) since 'left' is already NULL as you entered this conditional statement
                if(temp == NULL){
                    // Push the current node's value into 'ans'
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    
                    // Since you popped the current node from stack, check whether the right child of the current topmost node present in stack is equal to temp or not 
                    // i.e (temp == st.top()->right) . Here you are traversing backwards from leaf node to upwards until conditions are met
                    while(!st.empty() && temp == st.top()->right){
                        // Push the current topmost node's value into ans and pop it
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                
                else{
                    cur = temp;
                }
            }
        }
        
        return ans;
    }
};
