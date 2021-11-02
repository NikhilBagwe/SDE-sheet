// BRUTE ---------------------------------------------------------------- TC = O(n), SC = O(n)

// Find element whose freq is more than n/2 times where n=size of array

int main()
{
    vector<int> a {2,4,8,8,2,8,8};
    
    unordered_map<int,int> mp;
    
    for(int i=0; i<7; i++){
        mp[a[i]]++;
        if(mp[a[i]] >= 7/2) {
            cout<<a[i];
            break;
        }
    }
    
    return 0;
}

// OPTIMAL ----------------------------------------------------- MOORE'S VOTING ALGO ----------------------------------

/*
ALGO:
1. Select the 1st element as Candidate and so his votes are also '1'.
2. Iterate over the array amd find
   - If the current element is same as the candidate -> Increase the vote by 1
   - If the current element is diffrent than the candidate -> Decrease the vote by 1
   - If votes become 0, select the current element as the new candidate.
*/

int main()
{
    vector<int> a {2,4,2,8,2,2};
    int candidate = a[0];
    int votes = 1;
    for(int i=1; i<a.size(); i++){
        if(a[i] == candidate){
            votes++;
        }
        else if(a[i] != candidate){
            votes--;
        }
        
        if(votes == 0){
            candidate = a[i];
            votes = 1;
        }
    }
    
    // count the frequency of candidate in array 
    int freq = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] == candidate) freq++;
    }
    
    if(freq > a.size()/2) cout<<candidate;
    return 0;
}
