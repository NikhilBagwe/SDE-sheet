// BRUTE ================= O(n^2) ===============================================

int main()
{
    int a[] = {2, 4, 1, 3, 5};
    int n = 5;
    int inv = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                inv++;
                cout<<"["<<a[i]<<" "<<a[j]<<"] ";
            }
        }
    }
    
    cout<<endl;
    cout<<inv;

    return 0;
}

// OPTIMAL  ================================================================ TC=nlogn   SC=O(n) =============================================

#include <iostream>
using namespace std;

/*
LOGIC:
- While merging, whenever something comes from the right sub array, everything on the right of left pointer 'i' just
  gets added to inversion count.
*/

int merge1(int arr[], int temp[], int left, int mid, int right){
    int i, j, k, inv=0;
    i = left; // start of left sub array 
    j = mid;  // start of right sub arr
    k = left; // start of temp arr
    
    while((i <= mid-1) && (j <= right)){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
            // we do (mid-i) bcoz when (arr[i] > arr[j]), all the elements to right of 'i' are greater and pairs can be 
            // formed with them.
            // eg: left sub = [2 3 5]    right sub=[1 4]
            //                 i                    j
            // since (a[i] > a[j]) , we put 1 into the temp and then we can see that we can form pairs of 1 with all elements from left sub arr i.e from 'i' to 'mid'
            // so we add 3 to inv as, [1 2 3 5] -> there are 3 elements after 1.
            inv += (mid-i);
        }
    }
    
    while(i <= mid-1){
        temp[k++] = arr[i++];
    }
    
    while(j <= right){
        temp[k++] = arr[j++];
    }
    
    // copy back to original array 
    for(int m=left; m<=right; m++){
        arr[m] = temp[m]; 
    }
    return inv;
}

int mergeSort(int arr[], int temp[], int left, int right){
    int mid, inv = 0;
    if(left < right){
        mid = (left+right)/2;
        
        // left sub arr
        inv += mergeSort(arr, temp, left, mid);
        // right sub arr
        inv += mergeSort(arr, temp, mid+1, right);
        inv += merge1(arr, temp, left, mid+1, right);
    }
    return inv;
}

int main()
{
    int arr[] = {5,3,2,4,1};
    int n = 5;
    
    int temp[n];
    cout<<mergeSort(arr, temp, 0, n-1);

    return 0;
}
