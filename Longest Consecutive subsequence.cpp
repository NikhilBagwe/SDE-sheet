// BRUTE ================================================== TC = O(nlogn) ==============================================================================

int main()
{
    int a[] = {2,6,1,9,4,5,3};
    int n = 7;
    
    sort(a, a+n);
    int val = 1, count = 0;
    
    for(int i=0; i<n; i++){
        if(a[i] == val){
            count++;
            val++;
        }
    }
    
    cout<<count;

    return 0;
}

// OPTIMAL ======================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

/*
ALGO:
1. Put all the given elements into a Set.
2. Initialize a variable to store the "longest subsequence size" -> longestStreak.
3. Linearly traverse the array and check
   - Whether a number lesser by 1 than the current number exisits in the set and if it exists then skip the iteration
   - eg: set = [1 2 3 4 5 10 21]
     currentNum = 1 -> that means 1 is the most minimal value of the subsequence as '0' is not present, so enter the loop and start counting the longest subsequence.
4. If the (current num - 1) does not exist it means that the current num is the most minimal no. of the subsequence so do:
   - traverse the set until you are finding (current num + 1) and also update the currentStreak.
   - eg: traverse until currentNum=5 so the longestStreak=5 
5. Update the longestStreak with the maximum value.
*/

int main()
{
    vector<int> nums {2,6,1,9,4,5,3};
    int n = nums.size();
    
    set<int> hashSet;
    for(auto num : nums){
        hashSet.insert(num);
    }
    
    int longestStreak = 0;
    
    for(auto num : nums){
        // if the number lesser by 1 than the current no. does not exist than
        if(!hashSet.count(num-1)){
            int currentNum = num;
            int currentStreak = 1;
            
            // until a number greater by 1 than the num exist keep updating the currentStreak
            while(hashSet.count(currentNum+1)){
                currentNum++;
                currentStreak++;
            }
            
            longestStreak = max(longestStreak, currentStreak);
        }
    }
    
    cout<<longestStreak;
    
    return 0;
}
