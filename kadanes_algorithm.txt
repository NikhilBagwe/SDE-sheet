// ---- FIRST APPROACH WILL HAVE AN 0(N^3) COMPLEXITY -------------------------------------------------------------------------//

- ITEARTE OVER ALL THE SUB-ARRAYS USING 3 LOOPS


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


// ---- THIRD APPROACH WILL HAVE AN 0(N) COMPLEXITY ------------------------------------------------------------------------//

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

// ---- FOR ALL NEGATIVE ELEMENTS ------------------------------------------------------------------------//


#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] ={-1,-20,-3,-2,-5};
    int maxSum =INT_MIN, curSum=0;
    
    for(int i=0; i<5; i++){
        maxSum = max(maxSum,arr[i]);
    }
    cout<<maxSum<<endl;
    return 0;
}
