#include <bits/stdc++.h>
using namespace std;

int subsetSum(vector<int> &arr, int sum, int n){
    int t[n+1][sum+1];
    .
    for(int i=0; i<n+1; i++){
        t[i][0] = 1;
    }
    for(int i=1; i<sum+1; i++){
        t[0][i] = 0;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            
            // Instead of "||" operation use "+" operation as we have to find all possible no. of subsets.
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j];
            }
            
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    // return the total no. of subsets possible 
    return t[n][sum];
}

int main()
{
    vector<int> arr {2, 3, 5, 6, 8, 10};
    int k = 11;
    int n = arr.size()-1;
    cout<<subsetSum(arr, k, n);

    return 0;
}
