#include <bits/stdc++.h>
using namespace std;

set<string> printUnique(string input, string output, int n, set<string> &st){
    // Base case - when we reach to end of the i/p string, ouput the subset which is stored in 'output' string
    if(n >= input.size()){
        st.insert(output);
        return st;
    }
    
    // Not Pick
    printUnique(input, output, n+1, st);
    
    // Pick
    output += input[n];
    printUnique(input, output, n+1, st);
    
    return st;
}

int main()
{
    set<string> st;
    string s = "aab";
    
    printUnique(s, "", 0, st);
    
    for(auto it : st){
        cout<<it<<endl;
    }
    return 0;
}
