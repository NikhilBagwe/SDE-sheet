// BRUTE ======================================= The order is not maintained for other test cases =========== SC=O(n) ===========================================

int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = 6, mid=0;
    
    sort(arr, arr+n); // [-4, -1, 1, 2, 3, 4]
    
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            mid = i;
            break;
        }
    }
    
    vector<int> temp;
    
    int i=0, j=mid;
    while(i<mid && j<n){
        temp.push_back(arr[i]);
        temp.push_back(arr[j]);
        i++, j++;
    }
    
    while(j<n){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(auto it: temp){
        cout<<it<<" ";
    }

    return 0;
}

// OPTIMAL =====================================================================================

/*
ALGO: 3 Pointer appproach

1. Initialize 3 pointers:
    i -> Searches for negative no.
    j -> Searches for positive no.
    k -> used to traverse the array

2. On EVEN indexes we have -> negative no.
      ODD indexes we have  -> positive no.

3. Start traversing the arr using k and check that every index whether has the correct value as mentioned in STEP 2.

4. eg: arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8}
   - Here at ind=1 should be a positive no. but we have negative
   - Now point 'i' and 'j' at where 'k' is pointing i.e ind=1 and use 'j' to find the next positive no. which is
     at ind=2. So now swap index 1 and 2 but ORDER must be maintained.
     arr[] = {-5, 5, -2, 2, 4, 7, 1, 8, 0, -8}
     
5. Now at ind= 4 we have positive no. instead of negative no.
   - So now point 'i' and 'j' at ind=4 and use 'i' to find the next negative no. i.e at ind=9 
   - Now dont directly swap index 4 and 9 as it will break the order. So shift one by one element.
     arr[] = {-5, 5, -2, 2, 4, 4, 7, 1, 8, 0}
     arr[] = {-5, 5, -2, 2,-8, 4, 7, 1, 8, 0}
     
6. Whenever (i || j || k) >= n, STOP the traversal
*/

void rotate(int nums[], int start, int end){
    int temp = nums[end];
    for(int i = end-1; i >= start; i--){
        // assign previous element(eg: end-1) to next element(eg: last element i.e [i+1])
        nums[i+1] = nums[i];
    }
    nums[start] = temp;
}

int main()
{
    int nums[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = 10;
    
    int i=0, j=0, k=0;
    
    while(i<n && j<n && k<n){
        // Even index must have negative no.
        if(k%2 == 0){
            // Check if whether a positive no. is present
            if(nums[k] >= 0){
                // Find the 1st negative no.
                i=k;
                j=k;
                while(i<n && nums[i]>=0) i++;
                if(i >= n) break;
                rotate(nums, i, j);
            }
        }
        
        // For ODD index
        else{
            // If negative no. is present at odd index
            if(nums[k] < 0){
                i=k;
                j=k;
                while(j<n && nums[j]<0) j++;
                if(j >= n) break;
                rotate(nums, i, j);
            }
        }
        
        k++;
    }
    for(auto it: nums){
        cout<<it<<" ";
    }
    return 0;
}
