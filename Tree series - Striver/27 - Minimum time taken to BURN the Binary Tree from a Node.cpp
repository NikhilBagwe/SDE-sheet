// ======================= TC = O(n-findTargetNode-BFS traversal) + O(n-findMinTime) = O(n)
// ======================= SC = O(n-map) + O(n-queue) = O(n)

/*
- We are using BFS traversal as we have to travel radially i.e one level at a time to burn the adjacent nodes
- First we map all the parent pointers and store them in a map. Also find the target node i.e 'start'
- Then we again traverse the tree from targetnode and start burning node also calculate the time
*/

#include<bits/stdc++.h> 

// Finds the minimum time required to burn the tree from target node. Here we traverse radially for each node
int findMinTime(BinaryTreeNode<int>* target, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent_pointer){
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*, int> visited;
    visited[target] = 1;
    int minTime = 0;
    
    while(!q.empty()){
        int size = q.size();
        // To keep a check whether we have burned atleast 1 node in the iterations
        int flag = 0;
        
        // We are considering all nodes in the queue at a time so we are looping on the queue
        for(int i=0; i<size; i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            
            // For each node we are traversing radially, i.e left, right and upwards
            // Traverse the child nodes
            if(node->left && !visited[node->left]){
                flag=1;
                visited[node->left] = 1;
                q.push(node->left);
            }
            if(node->right && !visited[node->right]){
                flag=1;
                visited[node->right] = 1;
                q.push(node->right);
            }
            
            // Traverse the upward node
            if(parent_pointer[node] && !visited[parent_pointer[node]]){
                flag=1;
                visited[parent_pointer[node]] = 1;
                q.push(parent_pointer[node]);
            }
        }
        // If we have burned a adjacent node in above for loop iterations then flag will be '1', so increase minTime by 1 second
        if(flag) minTime++;
    }
    return minTime;
}

// Finds the target node from which we have to burn the tree and also maps parents of every nodes into parent_pointer map
BinaryTreeNode<int>* findTargetNode(BinaryTreeNode<int>* root, unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> &parent_pointer, int start){
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    BinaryTreeNode<int>* targetNode;
    
    while(!q.empty()){
        BinaryTreeNode<int>* node = q.front();
        q.pop();
        // To find target node
        if(node->data == start) targetNode = node;
        
        if(node->left){
            parent_pointer[node->left] = node;
            q.push(node->left);
        }
        if(node->right){
            parent_pointer[node->right] = node;
            q.push(node->right);
        }
    }
    return targetNode;
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    // parent pointer map - stores parent/root node of every node in the tree
    unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*> parent_pointer;
    // Find the target node from where we have to burn tree
    BinaryTreeNode<int>* target = findTargetNode(root, parent_pointer, start);
  
    int time = findMinTime(target, parent_pointer);
    return time;
}
