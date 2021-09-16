// BRUTE ==========================================================================================================================================================

int main()
{
    int a[] = {1, 4, 45, 6, 0, 19};
    int n = 6, x=51;
    
    // Stores size of the smallest subarray 
    int ans = INT_MAX;
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum = a[i];
        // When the current number is greater than 'x', thus size of subarray will be '1'
        if(sum > x){
            cout<<1;
            return 0;
        };
        
        // Iterate from a[i] till n-1 elements and check when sum becomes greater than 'x'
        for(int j=i+1; j<n; j++){
            sum += a[j];
            if(sum > x){
                // Store the minimum size of the subarray 
                // We can find the length of current subarray by doing (j-i+1)
                ans = min(ans, (j-i+1));
                break;
            }
        }
    }
    
    cout<<ans;

    return 0;
}
