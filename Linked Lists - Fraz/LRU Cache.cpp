// ============================================== TC = 0(1) , in worst case to find element in map will be O(n) which is very rare ======================================

class LRUCache {
public:
    class node{
        public:
            int key;
            int val;
            node* next;
            node* prev;

            node(int _key, int _val){
                key = _key;
                val = _val;
        }
    };
    
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    
    int cap; // stores the total capacity of LRU cache
    unordered_map<int, node*> m;
    
    // Init the LRU cache Data structure
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node *newnode){
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node *delnode){
        node *delnext = delnode->next;
        node *delprev = delnode->prev;
        delnext->prev = delprev;
        delprev->next = delnext;
    }
    
    int get(int key) {
        if(m.find(key) != m.end()){
            // Store the address of the given node as we are going to delete it later and then add it to the start again as it will become the "Last Recently Used" node
            node* resnode = m[key];
            int res = resnode->val;
            // Now delete it from map as it is the old address - We can omit this step also as anyway we are updating the address on line 57
            //m.erase(key);
            // Now delete the node and reassign it back by adding it to the start of DLL i.e after head
            deletenode(resnode);
            addnode(resnode);
            // Now store the new address of the node
            m[key] = head->next;
            return res;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        // Check whether the node already exists or not
        if(m.find(key) != m.end()){
            node *existingnode = m[key];
            m.erase(key);
            deletenode(existingnode);
        }
        
        // If the capacity of LRU is full, delete the "Least recently Used node" which is present just before 'tail' node
        if(m.size() == cap){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        
        // Now add our new node to the start i.e right after 'head'
        addnode(new node(key, value));
        // Update the new address in map
        m[key] = head->next;
    }
};
