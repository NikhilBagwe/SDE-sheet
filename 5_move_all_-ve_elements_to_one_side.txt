#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];
    
    // i is pointing to place before 0
    int i = -1;
    // using Partition algorithm
    int pivot = 0;
    
    for(int j = 0; j<n; j++){
        
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}
