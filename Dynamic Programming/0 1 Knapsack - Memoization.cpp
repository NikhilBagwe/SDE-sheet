#include <bits/stdc++.h>
using namespace std;

/* 
=> Memoization :

1. Write the recurssive code first.
2. Find the paramenters which are changing while making a recurssive calls. In our case 'capacity' and 'n' are changing
3. Create a matrix 'Globally' using this changing paramenters as rows*columns.
4. Initialize the whole matrix cells as '-1' using memset.
5. Every time a recurssive call is ended, a value is returned. Store that value into matrix.
6. When the function is called, always check whether the value is stored in matrix or it is '-1'. If the value at the
   desired position is not '-1', means it is a valid value that we calculated in some previous recurssive call, so return that value.

*/

int knapsack(vector<int> weight, vector<int> value, int capacity, int n){
    // Create matrix
    int t[n+1][capacity+1];
    memset(t, -1, sizeof(t));
    
    if(n == 0 || capacity == 0){
        return 0;
    }
    
    // Check whether the value exists in the matrix or not 
    if(t[n][capacity] != -1){
        return t[n][capacity];
    }
    
    if(weight[n-1] <= capacity){
        return t[n][capacity] = max(value[n-1] + knapsack(weight, value, capacity-weight[n-1], n-1), knapsack(weight, value, capacity, n-1));
    }
    
    else if(weight[n-1] > capacity){
        return t[n][capacity] =  knapsack(weight, value, capacity, n-1);
    }
    
    return 0;
}

int main()
{
    vector<int> weight {1,3,4,5};
    vector<int> value {1,4,6,7};
    int capacity = 7;
    int n = weight.size()-1;
    
    int ans = knapsack(weight,value,capacity,n);
    cout<<ans;

    return 0;
}
