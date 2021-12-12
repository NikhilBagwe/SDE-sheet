// TC = SC = O(n)

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        
        string s = "";
        // Simple Level order traversal
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            // If node is null, append '#' to string or append the node's value if it's not null
            if(node == NULL) s.append("#,");
            else s.append(to_string(node->val) + ',');
            
            // Small change in BFS - instead of checking for node's left and right only check for 'node' and push the child nodes even if one of them is null
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;
        
        // The stringstream class in C++ allows a string object to be treated as a stream. It is used to operate on strings. By treating the strings as streams 
        // we can perform extraction and insertion operation from/to string just like cin and cout streams
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        
        // Creates the root node -> TreeNode(int x) : val(x), left(NULL), right(NULL) - from definition in Leetcode
        // stoi() function converts a string to an integer value
        TreeNode* root = new TreeNode(stoi(str)); 
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#"){
                node->left = NULL;
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s, str, ',');
            if(str == "#"){
                node->right = NULL;
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        
        return root;
    }
};
