// OPTIMAL --------------------------------- HASHMAP ----------------------------------------------- TC = O(n), SC = O(n)

#include<bits/stdc++.h>
vector<int> majorityElementII(vector<int> &a)
{
	  int n = a.size();
    unordered_map<int, int> m;
    vector<int> ans;
    
    for(int i=0; i<n; i++){
        m[a[i]]++;
        if(m[a[i]] > n/3){
            ans.push_back(a[i]);
            m[a[i]]-=3;
        }
    }
    
    return ans;
}

// BETTER ------------------------------------------------------------------------------------------------ TC=O(N) ----- Extended MOORE'S VOTING ALGO

/* 
ALGO:

1. Initialize 2 candidates (num1, num2) and set there count to 0
2. When any of them count is 0, assign the current element as the new candidate and increase the count by 1.
3. When the current element is same as num1 or num2, increase the count accordingly.
4. When the current element is not same as num1 or num2, decrease the count accordingly.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a {1,1,1,8,8,5,5,5};
    int num1 = -1, num2 = -1;
    int count1 = 0, count2 = 0;
    
    for(int i=0; i<a.size(); i++){
        if(a[i] == num1){
            count1++;
        }
        else if(a[i] == num2){
            count2++;
        }
        else if(count1 == 0){
            num1 = a[i];
            count1 = 1;
        }
        else if(count2 == 0){
            num2 = a[i];
            count2 = 1;
        }
        else{
            count1--;
            count2--;
        }
    }
    
    int f1=0, f2=0;
    
    for(int i=0; i<a.size(); i++){
        if(a[i] == num1) f1++;
    }
    for(int i=0; i<a.size(); i++){
        if(a[i] == num2) f2++;
    }
    
    int n = a.size();
    if(f1 > n/3) cout<<num1<<endl;
    if(f2 > n/3) cout<<num2<<endl;

    return 0;
}
