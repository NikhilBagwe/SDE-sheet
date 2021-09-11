// ---- FIRST APPROACH WILL HAVE AN 0(N^3) COMPLEXITY -------------------------------------------------------------------------//

// - ITEARTE OVER ALL THE SUB-ARRAYS USING 3 LOOPS

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    
    // INT_MIN bcoz the max value can be negative also
    int max = INT_MIN;
    
    for(int i=1; i<=n; i++){
        
        for(int j=i; j<=n; j++){
            int sum = 0;
            
            for(int k=i; k<=j; k++){
                sum += a[k];
            }
            
            if(sum > max){
                max = sum;
            }
        }
    }
    
    cout<<max;
    return 0;
}

// test case -  7
//              7 5 -13 5 10 -2 5
// o/p - 18

// ---- SECOND APPROACH WILL HAVE AN 0(N^2) COMPLEXITY ------------------------------------------------------------------------//

int main()
{
    int arr[] ={-1,-2,-3,-4,-5};
    int n = 5;
    int maxSum = 0;
    
    for(int i = 0; i < n; i++){
        int sum = 0;
            
        for(int j = i; j < n; j++){
            sum += arr[j]; 
        }
        if(maxSum < sum){
            maxSum = sum;
        }
        
    }
    
    cout<<maxSum<<endl;
    return 0;
}


// ---- THIRD APPROACH WILL HAVE AN 0(N) COMPLEXITY -------------------------------- GREEDY APPROACH ----------------------------------------//

int main()
{
    int arr[] ={5,-4,-2,6,-1};
    int maxSum =0, curSum=0;
    
    for(int i=0; i<5; i++){
        curSum += arr[i];
        
        if(maxSum < curSum){
            maxSum = curSum;
        }
        
        // when curSum becomes negative, it means the current subarray does not provide the largest sum so, set curSum to 0
        else if(curSum < 0){
            curSum = 0;
        }
    }
    cout<<maxSum<<endl;
    return 0;
}

// ---- HANDLES BOTH POSITIVE AND NEGATIVE ELEMENTS ------------------------------ DYNAMIC PROG. APPROACH ----------------------------------------//

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;
    int curSum = a[0];
    int maxSum = a[0];
    
    for(int i=1; i<n; i++){
        curSum = max(a[i], curSum+a[i]);
        maxSum = max(maxSum, curSum);
    }
    
    cout<<maxSum;
    
    return 0;
}
