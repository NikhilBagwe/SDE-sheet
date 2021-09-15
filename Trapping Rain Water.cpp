// BRUTE ======================================================= O(n^2) ==================================================================================

int main()
{
    int a[] = {3, 0, 2, 0, 4};  // waterTrapped = 7
    int n = 5, waterTrapped=0;
    
    // traverse the array for each element and find maximum height on left side(i.e maxLeft) and maximum height on right side(i.e maxRight) respectively for each element
    for(int i=0; i<n; i++){
        
        int maxLeft = a[i];
        // to find maxLeft, traverse from the start of array to the current element i.e a[i]
        for(int j=0; j<i; j++){
            maxLeft = max(maxLeft, a[j]);
        }
        
        // to find maxRight, traverse from the next consecutive element of a[i] to end of array.
        int maxRight = a[i];
        for(int k=i+1; k<n; k++){
            maxRight = max(maxRight, a[k]);
        }
        
        waterTrapped += min(maxLeft, maxRight) - a[i];
    }
    
    cout<<waterTrapped;

    return 0;
}

// BETTER  =============================================================== TC = O(n) , SC = O(n)  ====================================================================

int main()
{
    int a[] = {3, 0, 2, 0, 4};  // waterTrapped = 7
    int n = 5, waterTrapped=0;
    
    int maxLeft = 0, maxRight = 0;
    
    // Stores the maximum height from left to right
    int prefixArr[n] = {0};   // [3 3 3 3 4]
    
    // Stores the maximum height from right to left 
    int suffixArr[n] = {0};   // [4 4 4 4 4]
    
    // Store the 1st element a[0] into prefixArr[0] for comparison purpose
    prefixArr[0] = a[0];
    for(int i=1; i<n; i++){
        prefixArr[i] = max(prefixArr[i-1], a[i]);
    }
    
    // Store the Last element a[n-1] into prefixArr[n-1] for comparison purpose
    suffixArr[n-1] = a[n-1];
    // Start traversing from 2nd last element of a[] as we are considering the last element i.e 'i+1' for comparison
    for(int i=n-2; i>=0; i--){
        suffixArr[i] = max(suffixArr[i+1], a[i]);
    }
    
    for(int i=0; i<n; i++){
        waterTrapped += min(prefixArr[i], suffixArr[i]) - a[i];
    }
    
    cout<<waterTrapped;

    return 0;
}
