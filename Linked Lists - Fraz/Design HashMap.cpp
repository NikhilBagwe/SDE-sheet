// BRUTE ==================================================================================================================================

// Use a vector as a frequency array and treat the indexes as "keys" and elements stored at given indexes as "values".

class MyHashMap {
public:
    vector<int> m;
    int size;
    
    MyHashMap() {
        size = 1e6 + 1;
        m.resize(size);
        // Init the whole array by '-1' as when an element is not present we have to return '-1'
        fill(m.begin(), m.end(), -1);
    }
    
    void put(int key, int value) {
        m[key] = value;
    }
    
    int get(int key) {
        return m[key];
    }
    
    void remove(int key) {
        m[key] = -1;
    }
};

// OPTIMAL =============== Handles Collisions =================================================================================================================

/*
- Here we create a Vector of Doubly LL that stores pairs i.e key value pairs.
*/
class MyHashMap {
public:
    vector<list<pair<int, int>>> m;
    int size;
    
    MyHashMap() {
        size = 1000;
        m.resize(size);
    }
    
    int hash(int key){
        return key%size;
    }
    
    list<pair<int, int>> :: iterator search(int key){
        int i = hash(key);
        // We can't use find function from STL here, as we only know the key , not the value. So we use a iterator and check m[i] from start till end
        list<pair<int, int>> :: iterator it = m[i].begin();
        while(it != m[i].end()){
            if(it->first == key) return it;
            it++;
        }
        return it;
    }
    
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        m[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>> :: iterator it = search(key);
        // If the key dosen't exist then return -1
        if(it == m[i].end()) return -1;
        // Else return the value of the key
        else return it->second;
    }
    
    void remove(int key) {
        int i = hash(key);
        // Check if the element to be deleted is present or not and then only remove and erase it or else it will throw error
        list<pair<int, int>> :: iterator it = search(key);
        if(it != m[i].end()) m[i].erase(it);
    }
};
