#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weight, vector<int> val, int cap, int n){
    int t[n+1][cap+1];
    
    // Base condition - Initialization process of 0th column and row
    for(int i=0; i<n+1; i++){
        for(int j=0; j<cap+1; j++){
            // Initialize the 0th row & column as '0'
            if(i == 0 || j == 0){
                t[i][j] = 0;
            }
        }
    }
    
    // Based on the choice diagram
    // Start from '1st' row and column as we Initialized the 0th row and column above
    for(int i=1; i<n+1; i++){
        for(int j=1; j<cap+1; j++){
            
            // As of now -> i = n , j = cap
            // For every valid item whose weight <= capacity, we have 2 choices -> Include it or Don't Include it
            if(weight[i-1] <= j){
                t[i][j] = max(val[i-1] + t[i-1][j-weight[i-1]], t[i-1][j]);
            }
            
            // when weight of the item is more than the capacity of bag, don't include it 
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    // t[n][cap] -> stores the final ans required by us
    return t[n][cap];
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
