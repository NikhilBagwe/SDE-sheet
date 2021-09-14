// BRUTE   ============================================================== TC = O(nlogn) ===============================================================================

int main()
{
    int a[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = 8, k=4;
    
    sort(a, a+n);  // 1 1 2 2 2 3 3 3
    int barrier = n/k;
    int freq = 0;
    int count = 0;
    
    for(int i=0; i<n; i++){
        if(a[i] == a[i+1]){
            freq += 2;
        }
        
        // make freq '0' or else result will be wrong
        if(a[i] != a[i+1]){
            freq = 0;
        }
        
        //cout<<i<<" "<<count<<" "<<freq<<endl;
        
        if(freq > barrier){
            count++;
            freq = 0;
        }
    }
    
    cout<<count;
    
    return 0;
}

// OPTIMAL  ======================================================================= TC = O(n) , SC = O(n) ===================================================================

// link = https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

int main()
{
    int a[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = 8, k=4;
    
    map<int, int> mp;
    int barrier = n/k;
    
    // store the frequency of each element in the map 
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }
    
    int count = 0;
    
    cout<<"Elements that appear more than n/k: ";
    for(int i=0; i<mp.size(); i++){
        if(mp[i] > barrier){
            count++;
            // Prints the element that appears more then n/k times
            cout<<i<<" ";
        }
    }
    
    cout<<endl;
    cout<<"Total : "<<count;
    
    return 0;
}
