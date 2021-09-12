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
