// Brute approach - Sort the array and linearly traverse to find the duplicate no. at a[i] and a[i+1]  =========== O(nlogn) ========================

int main()
{
    int a[]={1,3,4,2,2};
    int n = 5;
    sort(a, a+n);
    
    for(int i=0; i<n; i++){
        if(a[i] == a[i+1]){
            cout<<a[i];
        }
    }
    
    return 0;
}

// Better - Create a frequency array of size n and linearly traverse the given array and perform HASHING  =============== TC = O(n), SC = O(n) ======================

int main()
{
    int a[]={1,3,4,2,2};
    int n = 5;
    int temp[n];
    
    for(int i=0; i<n; i++){
        temp[a[i]]++;
    }
    
    for(int i=0; i<n; i++){
        if(temp[a[i]] > 1){
            cout<<a[i];
            break;
        }
    }
    
    return 0;
}

// OPTIMAL - 

#include <iostream>
using namespace std;

/*
Algo:
1. Initialize 2 pointers - Fast and slow pointers and point them to first element of array.
2. The slow ptr moves by 1 step, while the fast ptr moves by 2 steps.
3. Run a while loop until the fast and slow pointers become equal and stop at that point.
4. Now place the fast ptr at the start of array.
5. Now move both the pointers simultaneously by 1, and the point where they collide will be your duplicate number.
*/

int main()
{
    int nums[] = {1,3,4,2,2};
    
    int slow = nums[0];
    int fast = nums[0];
    
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    
    fast = nums[0];
    
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    cout<<slow;
    return 0;
}

