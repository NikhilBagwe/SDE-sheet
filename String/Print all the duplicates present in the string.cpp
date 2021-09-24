#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "geeksforgeeks";
    map<char, int> mp;
    
    // Store the string's elements into a map as pair of = 'char'->'int'
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }
    
    // Traverse the map using for each loop and check for elements whose count(value) is more than 1 i.e they are duplicates
    for(auto it : mp){
        if(it.second > 1){
            cout<<it.first<<" count : "<<it.second<<endl;
        }
    }

    return 0;
}
