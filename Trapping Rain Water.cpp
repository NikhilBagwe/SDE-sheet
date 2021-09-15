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
