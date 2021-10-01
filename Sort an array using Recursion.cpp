
#include <bits/stdc++.h>

using namespace std;

void insert(vector<int> &v, int temp){
    // Base case - When the array is empty OR temp >= last element in the array 
    if(v.size() == 0 || v[v.size()-1] <= temp){
        v.push_back(temp);
        return;
    }
    
    // Hypothesis - pop the last element and call insert() again
    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);
    
    // Induction - Add the poped element back into the array
    v.push_back(val);
    return;
}

void sortArr(vector<int> &v){
    // Base case - when there is only 1 element in the array, it is always sorted
    if(v.size() == 1){
        return;
    }
    
    // Hypothesis - reduce the length of array by removing one element from the end 
    int temp = v[v.size()-1];
    v.pop_back();
    sortArr(v);
    
    // Induction function - Add the poped element back into the array 
    insert(v, temp);
    return;
}

int main()
{
    vector<int> v {0,5,2,1,4,1};
    sortArr(v);
    for(auto it:v){
        cout<<it<<" ";
    }

    return 0;
}
