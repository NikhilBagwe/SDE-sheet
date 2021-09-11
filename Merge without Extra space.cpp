// BRUTE - Normal merge sort for merging two sorted arrays ============ SC-O(n+m) =========

int main()
{
    int a1[] = {1, 3, 5, 7};
    int a2[] = {0, 2, 6, 8, 9};
    int n = 4, m =5;
    
    int temp[n+m];
    int i = 0, j = 0, k = 0;
    
    while(i<n && j<m){
        if(a1[i] > a2[j]){
            temp[k++] = a2[j++];
        }
        if(a1[i] < a2[j]){
            temp[k++] = a1[i++];
        }
    }
    
    while(i<n){
        temp[k++] = a1[i++];
    }
    
    while(j<m){
        temp[k++] = a2[j++];
    }
    
    for(int i = 0; i<n+m; i++){
        cout<<temp[i]<<" ";
    }

    return 0;
}

// OPTIMAL - ================== TC = (n+m)log(n+m) SC = O(1) ====================================================================================

#include <iostream>
using namespace std;

/* 
eg: arr1 = [1,3,5,7] n=4
    arr2 = [0,2,6,8,9] m=5

ALGO :
1. Initialize 3 pointers - i, j and k where
    i - points to starting index of array 1.
    j - points to starting index of array 2.
    i - points to last element of array 1.
2. We know that the last element of array 1 will be the largest in array 1 as both the arrays are sorted.
3. Our aim is to have the first 4 smallest element in arr1 and remaining elements in arr2 in increasing order as per our eg.
4. So we will compare arr1[i] and arr2[j] and if (arr1[i] > arr2[j]), then we will swap arr1[k] with arr2[j] and inc j and dec k.
   If (arr1[i] < arr2[j]) inc i and just 'continue' as 'i' points to a samll element and we have to keep small elements in arr1.
5. Perform step 4 until (i <= k && j < m).
6. After exiting while loop , SORT both the arrays.
*/

void swapNum(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int arr1[] = {1,3,5,7}; 
    int arr2[] = {0,2,6,8,9};
    int n=4, m=5;
    
    int i=0, j=0, k=n-1;
    
    while(i<=k && j<m){
        if(arr1[i] > arr2[j]){
           swapNum(arr2[j], arr1[k]); 
           j++;
           k--;
        }
        
        else if(arr1[i] < arr2[j]){
            i++;
            continue;
        }
    }
    
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    
    for(int i=0; i<n; i++){
        cout<<arr1[i]<<" ";
    }
    
    for(int i=0; i<m; i++){
        cout<<arr2[i]<<" ";
    }

    return 0;
}
