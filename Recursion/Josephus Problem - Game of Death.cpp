#include <bits/stdc++.h>
using namespace std;

void gameOfDeath(vector<int> v, int k, int index, int &ans){
    // Base - At last, after all people have died only one person will remain alive and that will be our answer
    if(v.size() == 1){
        ans = v[0];
        cout<<ans;
        return;
    }
    
    // Hypothesis - Kill the kth person from the current index thus, delete the element at which the person is killed
    // and also keep a track of index by using below formula
    index = (index + k) % v.size();
    v.erase(v.begin() + index);
    gameOfDeath(v, k, index, ans);
    
    // Induction - we don't need this step as we are discarding the element which has died as only one person will stay alive at last
    return;
}

int main()
{
    int n = 40, k = 7;
    vector<int> v;
    for(int i=1; i<=n; i++){
        v.push_back(i);
    }
    // as we consider (k=current_index+k) for the current element so we should also consider the current positon and subtract 1 from k
    k--;
    int index = 0;
    int ans = -1;
    
    gameOfDeath(v, k, index, ans);

    return 0;
}
