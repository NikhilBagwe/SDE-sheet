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
