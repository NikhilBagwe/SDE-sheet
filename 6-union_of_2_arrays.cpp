#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    
    int a[n], b[m];
    
    unordered_map<int,int> map;
    
    for(int i = 0; i < n; i++){
        // insert value into array
        cin>>a[i];
        // at the same time insert the key into map and increment its value by 1
        map[a[i]]++;
    }
    
    for(int i = 0; i < m; i++){
        
        cin>>b[i];
        map[b[i]]++;
    }
    
    // as the map will store unique elements only, "size of map = size of union of array"
    cout<<map.size()<<endl;

    return 0;
}

TEST CASE:
6 2
85 25 1 32 54 6
85 2
7 <- ans
