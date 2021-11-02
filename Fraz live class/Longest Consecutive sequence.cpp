//BRUTE ------------------------------------------------------ n^2 -------------------------------------------------------------------------------------

#include <bits/stdc++.h>

using namespace std;
bool findNum(int start, int arr[]){
    for(int i=0; i<6; i++){
        if(arr[i] == start){
            return true;
        }
    }
    return false;
}
int main()
{
    int a[] = {5,6,10,13,7,12};
    int ans=0;
    for(int i=0; i<6; i++){
        int start=a[i];
        while(findNum(start, a)){
            start++;
        }
        
        ans=max(ans,start-a[i]);
    }

    cout<<ans;
    return 0;
}

// OPTIMAL -------------------------------------------------------------- O(nlogn) -------------------------------------------------------------------------------------

int main()
{
    vector<int> a {5,11,10,9,7,1};
    int sequencelen = 1;
    int maxlen = 1;
    sort(a.begin(), a.end());
    // 5,7,9,10,11,12
    // Stand on a number and check whther the prev number is 
    // less than the current no. by 1 
    for(int i=1; i<a.size(); i++){
        if(a[i] == a[i-1]+1){
            sequencelen++;
        }
        else if(a[i] == a[i-1]) continue;
        else{
            sequencelen = 1;
        }
        maxlen = max(sequencelen, maxlen);
    }
    

    cout<<maxlen;
    return 0;
}

//BETTER ----------------------------------------------------------- O(N) -------------------------------------------------------------------------------------

int main()
{
    vector<int> a {5,11,10,9,7,12};
    int ans = 1;
    unordered_set<int> box;
    
    for(int i=0; i<a.size(); i++){
        box.insert(a[i]);
    }
    
    for(int i=0; i<a.size(); i++){
        int start = a[i];
        
        // check whether prev number exists or not and skip the iteration
        if(box.find(start-1) != box.end()) continue;
        
        // this while loop runs very few times
        while(box.find(start) != box.end()){
            start++;
        }
        
        ans = max(ans, start-a[i]);
    }

    cout<<ans;
    return 0;
}
