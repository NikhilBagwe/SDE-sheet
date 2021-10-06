// link = https://leetcode.com/problems/letter-case-permutation/

#include <bits/stdc++.h>
using namespace std;

void changeCase(string ip, string op){
    if(ip.size() == 0){
        cout<<op<<endl;
        return;
    }
    
    // If the current i/p element is an alphabet
    if(isalpha(ip[0])){
        string op1 = op;
        string op2 = op;
        
        op1.push_back(tolower(ip[0]));
        op2.push_back(toupper(ip[0]));
        
        ip.erase(ip.begin()+0);
        
        changeCase(ip, op1);
        changeCase(ip, op2);
    }
    // If the current i/p element is a number
    else{
        string op1 = op;
        op1.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        changeCase(ip,op1);
    }
    
    return;
}

int main()
{
    string s = "a1B2";
    string output = "";
    
    changeCase(s, output);
    
    return 0;
}

/*
op:
a1b2
a1B2
A1b2
A1B2
*/
