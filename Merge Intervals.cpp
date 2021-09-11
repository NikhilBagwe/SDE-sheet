// BRUTE - For each interval , linearly traverse the whole intervals vector and merge intervals that meet the condition ============ O(n^2) =====================

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> mergedIntervals;
    
    if(intervals.size() == 0){
        return mergedIntervals;
    }
    
    sort(intervals.begin(), intervals.end());
    cout<<"Sorted intervals : ";
    for(auto it : intervals){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
    }
    cout<<endl;
   
    // Assign a temporary vector
    vector<int> temp={0,0}; 
   
    // linearly traverse the intervals 2D vector, for each interval
    for(auto it: intervals){
        // if the 1st element of current 'it' is smaller than the current 'temp', it means the interval pointed by 'it' is already merged so skip it
        // eg: temp=[1,6]  it=[2,4] -> here [2,4] is already considered so skip it.
        if(it[0] < temp[1]){
            continue;
        }
        
        else{
            temp = it;
            // consider temp=[8,9] , now iterate the intervals vector to find intervals that can be merged with it
            for(auto it : intervals){
               if(it[0] < temp[1]){
                  temp[1] = max(it[1], temp[1]);
               }
            }
            mergedIntervals.push_back(temp);
         }
     }
    
    for(auto it : mergedIntervals){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
    }
}

int main()
{
    vector<vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}, {16, 17}};
    merge(intervals);

    return 0;
}



// OPTIMAL =========================== TC = O(nlogn) + O(n) [sorting + linear traversal] =============================================

#include <bits/stdc++.h>
using namespace std;

/*
ASK to Interviewer :
1. Whether the given array of intervals is sorted or not?

ALGO:
1. Sort the 2D array as per the start time.
2. Store the 1st interval in a temp vector.
3. Linearly iterate over the 2D intervals vector, and compare the 1st element of 'it' i.e it[0] with 2nd element of
   of temp vector i.e tempInterval[1].
   eg: it= [2,4]   temp=[1,3]
   --> if (it[0] < temp[1]) = it means both intervals need to be merged and update temp[1] i.e [1, 4].
   eg: it= [8,9]   temp=[1,6]
   --> if (it[0] > temp[1]) = push tempInterval(containig the merged interval [1,6]) and reassign it with current 'it' i.e[8,9]
*/

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> mergedIntervals;
    
    if(intervals.size() == 0){
        return mergedIntervals;
    }
    
    sort(intervals.begin(), intervals.end());
    cout<<"Sorted intervals : ";
    for(auto it : intervals){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
    }
    cout<<endl;
    
    // put the first interval into tempInterval i.e a vector of size 2
    vector<int> tempInterval = intervals[0];  
    
    for(auto it : intervals){
        if(it[0] <= tempInterval[1]){
            tempInterval[1] = max(it[1], tempInterval[1]);
        }
        else{
            mergedIntervals.push_back(tempInterval);
            tempInterval = it;
        }
    }
    
    // push the final resultant merged interval into mergedIntervals
    mergedIntervals.push_back(tempInterval);
    
    for(auto it : mergedIntervals){
        cout<<"["<<it[0]<<","<<it[1]<<"]"<<" ";
    }
}

int main()
{
    vector<vector<int>> intervals {{1, 3}, {2, 6}, {8, 10}, {8, 9}, {9, 11}, {15, 18}, {2, 4}, {16, 17}};
    
    merge(intervals);

    return 0;
}
