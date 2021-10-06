// link = https://practice.geeksforgeeks.org/problems/permutation-with-spaces3627/1

#include <bits/stdc++.h>
using namespace std;

void permutation(string ip, string op){
    if(ip.size() == 0){
        cout<<op<<endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    // Choice 1 -> Include the 0th element of input with '_'
    op1.push_back('_');
    op1.push_back(ip[0]);
    
    // Choice 2 -> Include the 0th element of input without '_'
    op2.push_back(ip[0]);
    
    // Discard the 0th element of input as we have took decisions for it in above steps
    ip.erase(ip.begin() + 0);
    
    permutation(ip, op1);
    permutation(ip, op2);
    
    return;
}

int main()
{
    string s = "ABC";
    string output = "";
    
    // Include the 0th element of input into output as we cannot add spaces at the start and end of op string and then delete it
    output.push_back(s[0]);
    s.erase(s.begin() + 0);
    
    permutation(s, output);
    
    return 0;
}
