#include <iostream>
using namespace std;
bool subset_sum(int arr[], int sum, int n)
{
    bool t[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        t[i][0] = true;
    for (int i = 1; i <= sum; i++)
        t[0][i] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }

    return t[n][sum];
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    if (subset_sum(arr, sum, n))
        cout << "Subset is possible";
    else
        cout << "Subset not possible";
    return 0;

#include <bits/stdc++.h>

using namespace std;

int subsetSum(vector<int> &arr, int sum, int n){
    // rows * columns = size of array * sum 
    int t[n+1][sum+1];
    
    
    
    // Initialize the 0th column by '1' as even if we have required sum = 0, we can always form a null set from 
    // the given n size array.
    // Initialize the 0th row by '0' as if we were given an empty array i.e n=0; than we can never form the required sum from it
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            
            // For initializing COLUMN
            if(i == 0){
                t[i][j] = 1;
            }
            
            // For initializing ROW
            if(j == 0){
                t[i][j] = 0;
            }
        }
    }
    
    // From table , the 1st cell is going to be true i.e 1 
    t[0][0] = 1;
    
    // From table 
    for(int i=1; i<n+1; i++){
        for(int j=1; j<sum+1; j++){
            if(arr[i-1] <= j){
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
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
    vector<int> arr {2, 8, 7, 8, 10};
    int k = 11;
    int n = arr.size()-1;
    cout<<subsetSum(arr, k, n);

    return 0;
}
