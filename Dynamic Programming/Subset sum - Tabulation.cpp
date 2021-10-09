#include <bits/stdc++.h>
using namespace std;

bool subsetSum(vector<int> &arr, int sum, int n){
    // Matrix -> rows * columns = size of array * sum 
    bool t[n+1][sum+1];
    
    // Initialize the 0th column by '1' (true) as, even if we have required sum = 0, we can always form a null set from the given n size array.
    for(int i=0; i<n+1; i++){
        t[i][0] = true;
    }
    // Initialize the 0th row by '0' as if we were given an empty array i.e n=0; than we can never form the required sum from it
    for(int i=1; i<sum+1; i++){
        t[0][i] = false;
    }
    
    // From tabulation table -> i=n, j=sum
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            
            // If the current element in the array is <= current sum i.e 'j' -> We Pick it OR Not Pick the element
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            
            // (current element > j) -> Skip the element
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    
    // return the value stored in last cell
    return t[n][sum];
}

int main()
{
    vector<int> arr {2, 0, 7, 8, 10};
    int k = 11;
    int n = arr.size()-1;
    cout<<subsetSum(arr, k, n);

    return 0;
}
