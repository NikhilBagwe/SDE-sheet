#include <bits/stdc++.h>

using namespace std;
/*
- Algorithm:
1. Sort the array 
2. As we have to minimize the heights i.e find the minimum diff. so we have to increase the minimum value by k and decrease the maximum value by k.
   eg: 1st and last value of array -> 1 10 , k=4
       10 - 1 = 9 -> maximum diff
       so to get minimum diff. increase 1 by k & decrease 10 by k 
       6 - 5 = 1 -> minimum diff

source = https://www.youtube.com/watch?v=29uyA4F9t5I&t=964s&ab_channel=ShashwatTiwari
question = https://practice.geeksforgeeks.org/problems/minimize-the-heights3351/1
*/

int getMinDiff(int arr[], int n, int k){
    int min1=0, max1=0, r=0;
    sort(arr, arr+n);
    
    // r is the maximum diff possible after sorting arr
    r = arr[n-1] - arr[0]; // 9
    
    // we start from 1 as we considered the 1st diff above as 'r'
    for(int i=1; i<n;i++){
        if(arr[i] >= k){ 
            //cout<<i<<endl;
            max1 = max(arr[i-1]+k, arr[n-1]-k);
            //cout<<arr[i-1]+k<<" "<<arr[n-1]-k<<" "<<max1<<endl;
            min1 = min(arr[i]-k, arr[0]+k);
            //cout<<arr[i]-k<<" "<<arr[0]+k<<" "<<min1<<endl;
            r = min(r, max1-min1);
            //cout<<r<<endl;
        }
        else{
            continue;
        }
    }
    return r;
}
int main()
{
    int arr[]={1,5,8,10};
    int k=2, n=4;
    cout<<getMinDiff(arr,n,k);

    return 0;
}
