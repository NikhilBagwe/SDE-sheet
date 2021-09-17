// link = https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// BRUTE ==============================================================================================================================================================

/*
ALGO:
1. Iterate over the array and find favourable elements i.e (a[i] <= k).
2. Create a window of size = no. favourable elements.
3. Iterate the array and check the no. of elements in every possible window that need to be swapped in order to
   meet the condition i.e find nonFavourable elements.
*/

int main()
{
    int a[] = {2, 1, 5, 6, 3};
    int n=5, k=3;
    // int a[] = {2, 7, 9, 5, 8, 7, 4};
    // int n=7, k=7;
    
    // elements that are smaller or equal to 'k'
    int favourable = 0;
    // elements that are greater than 'k'
    int nonFavourable = 0;
    
    for(int i=0; i<n; i++){
        if(a[i] <= k)
            favourable++;
    }
    
    // Sliding window size = favourable elements count
    int start=0, end=favourable-1;
  
    int minSwap = INT_MAX;
    
    while(start<n && end<n){
        for(int i=start; i<=end; i++){
            if(a[i] > k)
                nonFavourable++;
        }
        
        minSwap=min(minSwap, nonFavourable);
        start++;
        end++;
        nonFavourable=0;
    }
    
    cout<<minSwap;
    return 0;
}
