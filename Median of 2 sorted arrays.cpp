// BRUTE ========================================================== SC = O(n+m) ==================================================================================
// Use merge sort and store the resultant array in temp array and then calculate the median

int main()
{
    int a1[] = {2, 4, 9, 12};
    int a2[] = {5, 6, 8, 13};
    int n = 5, m = 4;
    
    int temp[n+m];
    int i=0, j=0, k=0;
    
    while(i<n && j<m){
        if(a1[i] < a2[j]){
            temp[k++] = a1[i++];
        }
        
        else if(a1[i] > a2[j]){
            temp[k++] = a2[j++];
        }
    }
    
    while(i<n){
        temp[k++] = a1[i++];
    }
    
    while(j<n){
        temp[k++] = a2[j++];
    }
    
    for(int i=0; i<n+m; i++){
        cout<<temp[i]<<" ";
    }
    
    int ans = 0;
    int size1 = n+m;
    
    if(size1%2 == 0){
        int a = size1/2;
        int b = a - 1;
        ans = (temp[a]+temp[b])/2;
    }
    
    else{
        ans = temp[((size1+1)/2)-1];
    }
    
    cout<<"Median : "<<ans<<endl;

    return 0;
}

// OPTIMAL ===================================== Works for equal as well as different size arrays =============================================================================

/*
ALGO:
1. We have to find such a cut in the that divides both the arrays with equal elemennts on both sides.

2. This conditions must be met : l1 <= r2 and l2 <= r1
   eg: a1[] = {2 4 | 9 12}
       a2[] = {5 6 | 8 13}
   l1=4, r1=9, l2=6, r2=8

3. In the beginning we will place the cut after the 1st element of arr1. So now in order to have equal elements on both 
   the sides we need to take 3 elements from arr2 as we only took 1 element from arr1.
       a1[] = {2 | 4  9 12}
       a2[] = {5 6 8 | 13}
    now l1=2, r1=4, l2=8, r2=13 -> Don't satisfy the condition as l2 > r2 so increase the cut by 1 i.e after 4.

4. Now on increasing the cut, the conditions are satisfied.
       a1[] = {2 4 | 9 12}
       a2[] = {5 6 | 8 13}

5. EVEN elements :
   Since the size of arrays is even we need to find the 3,4 element for median.
   3rd -> the max or largest element on the left side of cut 
   4th -> the min or smallest element on the right side of cut
   Formula -> (max(l1, l2) + min(r1, r2)) /2
              = (6 + 8)/2 = 7
              
6. ODD elements :
   Formula -> min(r1, r2) /2
   
7. For DIFFERENT size arrays, always apply binary search on small size array to avoid out of bound error.
*/

#include <bits/stdc++.h>
using namespace std;

int medianOfSortedArrays(vector<int> vec1, vector<int> vec2){
    // When length are different than apply binary search on the shortest length array 
    if(vec1.size() > vec2.size()){
        return medianOfSortedArrays(vec2, vec1);
    }
    
    // Store the size of arrays 
    int n1 = vec1.size();
    int n2 = vec2.size();
    
    // Apply binary search on 1st array i.e vec1
    int low=0, high=n1;
    
    while(low <= high){
        
        // Initialize the cuts or partitions
        int cut1 = low + (high - low) / 2;
        // cut2 = Total required elements - Already present elements
        int cut2 = ((n1+n2)/2) - cut1;
        
        // Initialize l1, r1, l2, r2 and also check for extreme cases for out of bound errors
        int l1 = (cut1 == 0) ? INT_MIN : vec1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : vec2[cut2-1];
        
        int r1 = (cut1 == n1) ? INT_MAX : vec1[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : vec2[cut2];
        
        // Check for binary search conditions
        if(l1 > r2) high=cut1-1;    // Shift cut towards left side
        
        else if(l2 > r1) low=cut1+1; // Shift cut towards right side
        
        // When both conditions are satisfied return the median as per the size of array
        else{
            if((n1+n2)%2 == 0){
                return ((max(l1, l2) + min(r1, r2))/2);
            }
            else{
                return (min(r1, r2));
            }
        }
        
    }
    return 0;
}

int main()
{
    // vector<int> a1 {2, 3, 5, 8}; // 9
    // vector<int> a2 {10, 12, 14, 16};
    
    vector<int> a1 {-5, 3, 6, 12, 15};  // median=3
    vector<int> a2 {-12, -10, -6, -3, 4, 10};
    
    // vector<int> a1 {1, 12, 15, 26, 38};  // 16 
    // vector<int> a2 {2, 13, 17, 30, 45};
    
    cout<<medianOfSortedArrays(a1, a2);
    
    return 0;
}
