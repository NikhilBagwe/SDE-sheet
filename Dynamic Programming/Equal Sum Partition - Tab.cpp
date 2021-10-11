#include <bits/stdc++.h>
using namespace std;

/*
LOGIC:
1. If the sum of the given array is even than only we can make an equal partition of it.
   eg: arr = {1,5,11,5}
   [1,5,5] and [11]
2. So check whether the sum is even or odd and than use the same code as subset sum problem
*/

bool partition(vector<int> arr, int sum, int n){
    int t[n+1][sum+1];
    
    for(int i=0; i<n+1; i++){
        t[i][0] = true;
    }
    
    for(int i=1; i<sum+1; i++){
        t[0][i] = false;
    }
    
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i]] || t[i-1][j];
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    return t[n][sum];
}

int main()
{
    vector<int> v {1,5,11,5};
    int n = v.size()-1;
    
    int sum = 0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
    
    if(sum%2 != 0){
        cout<<"Partioning not possible";
        //cout<<partition(v, sum/2, n);
    }
    else{
        cout<<partition(v, sum/2, n);
    }

    return 0;
}
