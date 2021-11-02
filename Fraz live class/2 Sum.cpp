//OPTIMAL --------------------------------------------- TC = O(n), SC = O(n) -- Pairs may get repeated in 'ans' vector

int main()
{
    vector<int> v {7,3,1,4,8};
    int target = 9;
    unordered_map<int, int> m;
    pair<int,int> p;
    
    for(int i=0; i<v.size(); i++){
        m[v[i]]++;
    }
    
    for(int i=0; i<v.size(); i++){
        int x = target - v[i];
        if(m.find(x) != m.end()){
            p.first=v[i];
            p.second=x;
            break;
        }
    }
    
    cout<<p.first<<" "<<p.second;

    return 0;
}

// ONLY UNIQUE PAIRS ARE PUSHED INTO THE 'ans' vector ----------------------------------------------------------------------------------------------

vector<pair<int,int>> twoSum(vector<int>& v, int target, int n)
{
    vector<pair<int,int>> ans;
    unordered_map<int,int> m;
    
    for(int i=0; i<n; i++){
        m[v[i]]++;
        
        // Suppose if target=4 and v[i]=2, then check if freq of '2' is greater than 1 or not
        if(v[i] == target-v[i]){
            
            if(m[v[i]] > 1){
                ans.push_back({v[i], v[i]});
                // on adding to ans vector, decrement the freq by 2
            	  m[v[i]] -= 2;
            }
        }
        
        else{
            // Check whether both 'v[i]' and 'target-v[i]' freq is atleast one 
            if(m[v[i]] > 0 && m[target-v[i]] > 0){
                ans.push_back({v[i], target-v[i]});
                m[v[i]]-=1;
                m[target-v[i]]-=1;
            }
        } 
    }
    
    // If no pair is found
    if(ans.size() == 0)
    {
      ans.push_back({-1, -1});
    }
    
    return ans;
}
