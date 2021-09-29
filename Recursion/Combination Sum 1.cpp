#include <bits/stdc++.h>

using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    // When reach to the end of array 
    if(ind == arr.size()){
        // Check whether the target has became 0 or not 
        if(target == 0){
            // Then add the sequence of elements present in 'ds' to final 'ans'
            ans.push_back(ds);
        }
        return;
    }
    
    // Pick up the element -------------------------------------------------------------------------------
    
    if(arr[ind] <= target){
        // add arr[ind] to the 'ds'
        ds.push_back(arr[ind]);
        // Reduce the target by the value we have picked up i.e arr[ind]
        findCombination(ind, target-arr[ind], arr, ans, ds);
        // As we have to perform the "NOT PICK" recursion call shown below at line 30, we have to remove the arr[ind]
        ds.pop_back();
    }
    
    // Not pick up the element ---------------------------------------------------------------------------
    
    // Move to the next index as we wont pick up the element at current index
    findCombination(ind+1, target, arr, ans, ds);
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target){
    // Stores all the combinations 
    vector<vector<int>> ans;
    // Used in recursion
    vector<int> ds;
    
    findCombination(0, target, candidates, ans, ds);
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
  
    return ans;
}

int main()
{
    vector<int> candidates {2, 3, 6, 7};
    int target = 7;
    
    combinationSum(candidates, target);
    

    return 0;
}
