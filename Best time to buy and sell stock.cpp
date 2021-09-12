// BRUTE ====================================== O(n^2) =======================================================================================

int main()
{
    int a[] = {7,1,5,3,6,4};
    int n = 6, maxProfit=0;
    
    for(int i=0; i<n; i++){
        int currProfit = 0;
        for(int j=i+1; j<n; j++){
            // find the jth element that is greater than the element pointed by 'i'
            if(a[i] < a[j]){
                currProfit = a[j] - a[i];
                if(currProfit > maxProfit){
                    maxProfit =currProfit;
                }
            }
        }
    }
    
    cout<<maxProfit;

    return 0;
}


// OPTIMAL ========================================================== O(n) =============================================================================

int main()
{
    int a[] = {7,1,5,3,6,4};
    int n = 6, 
    
    int maxProfit=0;
    // Stores the minimum value to the left of pointer 'i'
    int minPrice = INT_MAX;
    
    for(int i=0; i<n; i++){
        // update the minimal value          iteration - 0  1  2  3  4  5
        minPrice = min(minPrice, a[i]);               // 7, 1, 1, 1, 1, 1
        // try to sell it at maximum Profit
        maxProfit = max(maxProfit, a[i] - minPrice);  // 0, 1, 4, 4, 5, 5 
    }
    
    cout<<maxProfit;

    return 0;
}
