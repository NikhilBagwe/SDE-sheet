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

// OPTIMAL ======================================================= TC= O(n) SLIDING WINDOW ==============================================================================

int main()
{
    int a[] = {1, 4, 45, 6, 0, 19};
    int n = 6, x=51;
    
    // Sliding Window technique
    
    // Initialize the window -> starts from the 1st element and ends on 2nd element
    int start=0, end=1;
    int ans = INT_MAX;
    
    // Store 1st element to sum
    int sum = a[start];
    
    // If the 1st element is greater than x than means size of minimum subarray=1 and exit the pgm.
    if(sum > x){
        cout<<1;
        return 0;
    }
    
    // if 'end' pointer is not exceeding size of given array 
    if(end < n) sum += a[end];
    
    // keep sliding the window until the window is inside the array
    while(start<n && end<n){
        
        // When (sum > x), try decreasing the size of window as we have to find the minimum subarray
        if(sum > x){
            ans = min(ans, (end-start+1));
            // Decrease size of window from backwards
            sum -= a[start];
            start++;
        }
        
        // If the desired sum is not acheived, increase the size of window from front by increasing end pointer
        else{
            end++;
            if(end < n){
                sum += a[end];
            }
        }
    }
    
    cout<<ans;

    return 0;
}
