#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    
    int arr[n];
    cout<<"Enter elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    // intialize counters for 0,1,2 to count their frequency
    int c1=0,c2=0,c3=0;
    
    for(int i=0; i<n; i++){
        if(arr[i] == 0) c1++;
        else if(arr[i] == 1) c2++;
        else c3++;
    }
    
    int k=0;
    // fill the array with 0,1,2 depending on their frequency
    for(int i = 0; i<c1; i++) arr[k++] = 0;
    for(int i = 0; i<c2; i++) arr[k++] = 1;
    for(int i = 0; i<c3; i++) arr[k++] = 2;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}
