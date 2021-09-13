// BRUTE ============================================================================================================================================================
// Fails for certain edge cases like a[]={-8 5 3 1 6} -> expected o/p=90, our o/p = 1

int main()
{
    int a[] = {2, 3, 4, 5, -1, 0};
    int n = 6;
    
    int maxProd=1, curProd=1;
    
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            curProd = 1;
            continue;
        }
        curProd *= a[i];
        
        if(curProd > maxProd){
            maxProd = curProd;
        }
        
    }
    cout<<maxProd;
    return 0;
}

// OPTIMAL ==============================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

/*
ALGO:
1. Assign 3 pointers max, min and result and point them to arr[0].
2. Traverse the array from 2nd element i.e arr[1] as we have already considered the 1st element above.
3. Inside loop check if current element is 0, and if it is 0 then update max=min=1 and skip the iteration.
4. Multiply the current element with min and max and store the result in separate temp variables.
5. Update max and min by comparing the temp variables, and than update result accordingly by comparing max with result.
*/

int main()
{
    long a[] = {-8, 5, 3, 1, 6};
    int n = 5;
    
    long min_val = a[0];
    long max_val = a[0];
    long res = a[0];
    
    for(int i=1; i<n; i++){
        if(a[i] == 0){
            max_val=1;
            min_val=1;
            continue;
        }
                          //iterations ->   1   2    3     4   
        long temp1 = a[i]*max_val;     // -40   15   15    90
        long temp2 = a[i]*min_val;     // -40  -120 -120  -720
        
        // update max 
        max_val = max(temp1, temp2);   // -40   15   15    90
        // check whether the current element is greater than max.
        max_val = max(max_val, a[i]);  //  5,   15   15    90
        
        min_val = min(temp1, temp2);   //  -40, -120 -120  -720
        min_val = min(min_val, a[i]);  //  -40, -120 -120  -720
        
        res = max(res, max_val);       //   5    15   15   90
    }

    cout<<res;
    
    return 0;
}
