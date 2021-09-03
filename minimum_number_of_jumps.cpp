#include <bits/stdc++.h>

using namespace std;

int getJump(int arr[], int n){
    
    // this the max point till which we can go 
    int maxReach = arr[0];
    // describes how much steps we can take from arr[0]
    int step = arr[0];
    // since we are considering the 1st element
    int jump = 1; 
    
    // when array has only one element
    if(n == 0) return 0;
    // when the 1st element itself is 0, means we can never jump from there
    else if(arr[0] == 0) return -1;
    
    else{
        for(int i=1; i<n; i++){
            // when i reaches the end of array
            if(i == n-1){
                return jump;
            }
            
            // We know maxReach=1, so when we go to next element arr[1] i.e 3, then maxReach=3 means we can go till arr[4] from 
            // arr[1]. So add i to arr[1] to keep a track of maxReach/ update maxReach
            maxReach = max(maxReach, i+arr[i]);
            // since we moved forward, reduce step 
            step--;
            
            // means we have reached the desired position and we have to jump from here
            if(step == 0){
                jump++;
                // if i becomes greater than maxReach, means our maxReach can never reach the end of arr
                if(i >= maxReach){
                    return -1;
                }
                // inorder to take the jump to reach maxReach
                step = maxReach - i;
            }
        }
    }
}

int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    int n = 11;
    cout<<getJump(arr,n);
    
    return 0;
}
