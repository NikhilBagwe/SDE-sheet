// BRUTE ==================================================== TC = O(n) , SC = O(n) =======================================================================

int main()
{
    int a1[] = {10, 5, 2, 23, 19};
    int n = 6;
    int a2[] = {19, 5, 2};
    int m = 3;
    
    // Store all elements of the bigger size array into hashSet
    set<int> hashSet;
    for(int i=0; i<n; i++){
        hashSet.insert(a1[i]);
    }
    
    int flag = 0;
    
    // Iterate the smaller array and check whether the hashSet contains all elements from smaller array
    for(int i=0; i<m; i++){
        if(hashSet.count(a2[i])){
            continue;
        }
        else{
            cout<<"No";
            flag = 1;
            break;
        }
    }
    
    if(flag == 0) cout<<"Yes";
    
    return 0;
}
