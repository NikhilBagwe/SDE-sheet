// BRUTE ============================================= TC = N^3xlogN SC=O(1) =========================================================================================

/*
ALGO:

1. Sort the array
2. Init 3 pointers.
3. Apply binary search on remaining elements i.e from 'k+1' to 'n-1' to find 4th number.
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {4,3,3,4,4,2,1,2,1,1};
    int n = 10, tar=9;
    sort(a, a+n);
    set<vector<int>> ans; // hashSet -> to store unique pairs
    
    // Initialize 3 pointers and to find the 4th number apply binary search
    int i, j, k;
    
    for(i=0; i<n; i++){
        for(j=i+1; j<n; j++){
            for(k=j+1; k<n; k++){
                int s=k+1, e=n-1;
                int target = tar- (a[i]+a[j]+a[k]);
                vector<int> v;
                
                // Apply binary search on remaining elements i.e from 'k+1' to 'n-1'
                while(s<=e){
                    int mid = s+(e-s)/2;
                    if(target == a[mid]){
                        v.push_back(a[i]);
                        v.push_back(a[j]);
                        v.push_back(a[k]);
                        v.push_back(a[mid]);
                        ans.insert(v);
                        break;
                    }
                    else if(target > a[mid]) e=mid-1;
                    else s=mid+1;
                }    
            }
        }
    }
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
}


// OPTIMAL ============================================= TC = O(N^3) =========================================================================================

/*
LOGIC:

1. Sort the array
2. Init 2 pointers.
3. Apply TWO SUM on remaining elements i.e from 'j+1' to 'n-1' to find 3rd and 4th number.
4. Here we are skipping the duplicates
*/

int main()
{
    vector<int> num {4,3,3,4,4,2,1,2,1,1};
    int n = num.size(), target=9;
    
    sort(num.begin(), num.end());
    
    vector<vector<int>> ans; // store unique pairs
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int target_2 = target - num[i] - num[j];
            
            int s = j+1, e = n-1;
            
            // Applying TWO SUM algo -------------------------------------------
            while(s < e){
                int two_sum = num[s] + num[e];
                
                if(two_sum < target_2) s++;
                
                else if(two_sum > target_2) e--;
                
                else{
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = num[i];
                    quadruplet[1] = num[j];
                    quadruplet[2] = num[s];
                    quadruplet[3] = num[e];
                    
                    ans.push_back(quadruplet);
                    
                    // Processing the duplicates of number 3 
                    while(s<e && num[s]==quadruplet[2]) s++;
                    
                    // Processing the duplicates of number 4
                    while(s<e && num[e]==quadruplet[3]) e--;
                }
            }
            
            // Processing the duplicates of number 2 
            // NOTE - Move to the last duplicate number only, as the for loop will move the 'j' by one again
            // eg: ...2 2 2 3 -> Move j to the last '2' just before '3', and then the for loop will automatically move the 'j' to '3', thus skipping the duplicates
            while(j+1 < n && num[j+1]==num[j]) ++j;
        }
        
        // Processing the duplicates of number 1
        while(i+1 < n && num[i+1]==num[i]) ++i;
    }
    
    for(auto it : ans){
        for(auto num : it){
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return 0;
}
