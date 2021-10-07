#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string s){
    // variables to keep a count of 1s and 0s
    int count0=0, count1=0;
    // count of substrings 
    int substringCount = 0;
    
    for(int i=0; i<s.size(); i++){
        if(s[i] == '0'){
        count0++;
        }
        else{
            count1++;
        }
        
        if(count0 == count1){
            substringCount++;
        }
    }
    return substringCount;
}

int main()
{
    string ip = "0100110101";
    int ans = maxSubstring(ip);
    cout<<ans;
    return 0;
}
