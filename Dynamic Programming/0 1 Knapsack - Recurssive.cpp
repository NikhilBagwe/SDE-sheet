
#include <bits/stdc++.h>
using namespace std;

// We have to return the maximum profit i.e sum of values of weigths that produces high profit

// capacity -> represents capacity of the bag
// n -> size of arrays
int knapsack(vector<int> weight, vector<int> value, int capacity, int n){
    // Base - think of smallest possible valid input 
    // 1. when there are no items left i.e n=0, means we can't store anything     OR 
    // 2. the capacity of bag is 0, meaning we cant store any item -> profit will be 0
    if(n == 0 || capacity == 0){
        return 0;
    }
    
    // From choice diagram
    // For every item we have 2 choices - Include the item or don't Include it 
    if(weight[n-1] <= capacity){
        return max(value[n-1] + knapsack(weight, value, capacity-weight[n-1], n-1), knapsack(weight, value, capacity, n-1));
    }
    
    // when weight of the item is more than the capacity of bag, don't include it 
    else if(weight[n-1] > capacity){
        return knapsack(weight, value, capacity, n-1);
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
