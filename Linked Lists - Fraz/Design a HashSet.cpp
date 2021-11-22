// BRUTE =====================================================================================================================================================

/*
Create a vector of size 10^6 + 1 and use it as a frequency array.
*/

class MyHashSet {
public:
    vector<int> hashSet;
    int size = 0;
    
    MyHashSet() {
        // We are adding '1' as vector has zero-based indexing so the last number i.e 1e9 cannot fit, so we add '1' to provide extra space
        size = 1e6+1;
        hashSet.resize(size);
    }
    
    void add(int key) {
        hashSet[key] = 1;
    }
    
    void remove(int key) {
        hashSet[key] = 0;
    }
    
    bool contains(int key) {
        return hashSet[key];
    }
};

// We can also use a small array like size=11 as hashSet, and store 22 elements into it by using modulo operator.
// eg: If we have to store 22, we will perform 22 % 11 = 0, so at arr[0] we will mark it as 1 meaning '22' is now stored. 
// But in future if we have to store '0' , there will be a collision problem as we have already marked '0' index as '1' when we stored '22'. So we use "CHAINING" technique.


// OPTIMAL ================= CHAINING ======================================================================================================

/*
- Here we make a vector of Doubly LL, so that we can avoid collisions and store keys in chains of Doubly LL.
- This increases the speed of functions as the array size can be reduced from 1e9 to just '100'
*/

class MyHashSet {
public:
    vector<list<int>> m;
    int size = 0;
    
    MyHashSet() {
        // If we increase the size to suppose 1000, the no. of collisions happening will be reduced but their is a trade-off that the time taken will be increased.
        size = 100;
        m.resize(size);
    }
    
    // Gives at which index or in which list our key is present
    int hash(int key){
        return key%size;
    }
    
    // Returns a pointer pointing to the key that we are finding
    list<int> :: iterator search(int key){
        int i = hash(key);
        return find(m[i].begin(), m[i].end(), key);
    }
    
    void add(int key) {
        // Check if the key exists already than directly return as we cannot insert duplicate elements
        if(contains(key)) return;
        int i = hash(key);
        m[i].push_back(key);
    }
    
    void remove(int key) {
        // Check if the key exists in the hashSet or not. If the key dosen't exists directly return.
        if(!contains(key)) return;
        int i = hash(key);
        m[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        // When the search func does not return m[i].end() means the key exists .
        if(search(key) != m[i].end()) return true;
        else return false;
    }
};











