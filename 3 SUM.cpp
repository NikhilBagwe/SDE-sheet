// Triplet Sum in Array
// OPTIMAL  ======================================== O(n^2) ==============================================================================================

int main()
{
    int a[] = {1, 4, 45, 6, 10, 8};
    int n = 6, x = 11;
    
    sort(a, a+n); // 1 4 6 8 10 45
    int k=n-1;
    int flag = 0;
    
    for(int i=0; i<n; i++){
        
        // Fix the 1st element i.e a[0] and then apply 2 pointer on (i+1) to (n-1) elements.
        int sum = x-a[i];  // sum = 13-1 =12
        int j = i+1;
        
        // Now find '12' using 2 pointer approach
        while(j < k){
            if((a[j]+a[k]) == sum){
                cout<<"Yes";
                flag = 1;
                break;
            }
            
            else if((a[j]+a[k]) > sum){
                k--;
            }
            
            else if((a[j]+a[k]) < sum){
                j++;
            }
        }
    }
    
    if(flag == 0) cout<<"No";
    
    return 0;
}

// OPTIMAL - 2 ===================================================== TC = O(n) , SC = O(n)  =========================================================================

int main()
{
    int a[] = {1, 4, 45, 6, 10, 8};
    int n = 6, x = 13;
    
    set<int> hashSet;
    // Stores the value that needs to be found from 1st to n elements as the 0th element is fixed
    int val = x - a[0];  // eg. val = 13-1 = 12
    int flag = 0;
    
    for(int i = 1; i < n; i++){
        // now find whether the (val-a[i]) i.e num is present in hashSet. If num is present means we can form the required sum i.e 'x' using 3 values which are-> a[0], current a[i] and num.
        int num = val - a[i];  // eg.i=0 -> num = 12-4 = 8 -> Therefore look whether '8' is present in hashSet
        if(hashSet.count(num)){
            cout<<"Yes";
            flag = 1;
            break;
        }
        
        // If num is not present, push the current element into hashSet
        else{
            hashSet.insert(a[i]);
        }
    }
    
    if(flag == 0) cout<<"No";

    return 0;
}
