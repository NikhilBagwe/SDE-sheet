// BRUTE ===================================================================================================================================

// Gives the no. of painters required to complete the task at a given capacity
int requiredPainters(vector<int> &boards, int cap){
    int painterNumber = 1;
    int remCapacity = cap; // remaining capacity of painter, which at start is FULL
    int n = boards.size();
    
    for(int i=0; i<n; i++){
        if(boards[i] <= remCapacity){
            remCapacity -= boards[i];
        }
        
        // When the size of boards[i] becomes greater than capacity of current painter, move to next painter as a painter can only paint contigous boards and that to he has to 
        // paint the full board i.e he cannot paint it half only
        else{
            painterNumber++;
            remCapacity = cap;
            remCapacity -= boards[i];
        }
    }
    
    return painterNumber;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int max_val=0, sum=0;
    
    for(int i=0; i<boards.size(); i++){
        sum += boards[i];
        // max_val -> maximum value in array
        max_val = max(max_val, boards[i]);
    }
    
    // i= max_val bcoz we have to paint the whole board, thus minimum capacity should be atleast equal to max_val
    for(int i=max_val; i<=sum; i++){
        if(requiredPainters(boards, i) <= k) return i;
    }
}

// OPTIMAL =============================================================================================================================================

// Gives the no. of painters required to complete the task at given capacity
int requiredPainters(vector<int> &boards, int cap){
    int painterNumber = 1;
    int remCapacity = cap; // remaining capacity of painter, which at start is FULL
    int n = boards.size();
    
    for(int i=0; i<n; i++){
        if(boards[i] <= remCapacity){
            remCapacity -= boards[i];
        }
        
        // When the size of boards[i] becomes greater than capacity of current painter, move to next painter
        else{
            painterNumber++;
            remCapacity = cap;
            remCapacity -= boards[i];
        }
    }
    
    return painterNumber;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    int max_val=0, sum=0, ans=0;
    int n = boards.size();
    for(int i=0; i<n; i++){
        sum += boards[i];
        max_val = max(max_val, boards[i]);
    }
    
    // Binary search -----------------------------------------------------------------
    int s=max_val, e=sum;
    
    while(s <= e){
        int mid = s+(e-s)/2;
        int painters = requiredPainters(boards, mid);
      
        // current 'mid' is also a possible answer but, also we can try reducing the capacity even more and check again whether we can find even samller answer
        if(painters <= k){
            ans = mid;
            e = mid-1;
        }
      
        // Increase the capacity
        else{
            s = mid+1;
        }
    }
    return ans;
}
