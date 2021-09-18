// link = https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

// BRUTE ==============================================================================================================================================================

/*
ALGO:
1. Iterate over the array and find favourable elements i.e (a[i] <= k).
2. Create a window of size = no. favourable elements.
3. Iterate the array and check the no. of elements in every possible window that need to be swapped in order to meet the condition i.e find minimum nonFavourable elements.
*/

int main()
{
    int a[] = {2, 1, 5, 6, 3};
    int n=5, k=3;
    // int a[] = {2, 7, 9, 5, 8, 7, 4};
    // int n=7, k=6;
    
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

// OPTIMAL ========================================================================================================================================================

int main()
{
    int a[] = {2, 1, 5, 6, 3};
    int n=5, k=3;
    
    int fav=0, nonFav=0;
    
    // find the favourable elements that satisfy (a[i] <= k) condition throughout the array 
    for(int i=0; i<n; i++){
        if(a[i] <= k) fav++;
    }
    
    // Consider the 'window size=no.of favourable elements' and thus find the nonFav elements present in the window
    // nonFav = no. of elements that needs to be swapped
    for(int i=0; i<fav; i++){
        if(a[i] > k) nonFav++;
    }
    
    // Optimized Sliding window
    int l=0, r=fav-1, result=INT_MAX;
   
    while(r < n){
        result = min(result, nonFav);
        // increase the window size from front side
        r++;
        // on increasing the size, if the new element included is greater than 'k' than increment nonFav 
        if(r<n && a[r]>k) nonFav++;
        // As we increase from front side, we also decrease from back side of window i.e l++. 
        // check whether the element pointed by 'l' is greater than k, and if so decrement 'nonFav' as we are moving the window forwards
        if(l<n && a[l]>k) nonFav--;
        l++;
    }

    cout<<result;
    return 0;
}
