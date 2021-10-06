#include <bits/stdc++.h>
using namespace std;

void changeCase(string ip, string op){
    if(ip.size() == 0){
        cout<<op<<endl;
        return;
    }
    
    string op1 = op;
    string op2 = op;
    
    // Choice 1 -> Include the 0th element directly as it is i.e in lowercase.
    op1.push_back(ip[0]);
    
    // Choice 2 -> Include the 0th element by converting it to uppercase
    op2.push_back(toupper(ip[0]));
    // to handle mix input cases eg: aBc
    // char ans = islower(ip[0]) ? toupper(ip[0]) : tolower(ip[0])
    // op2.push_back(ans);
    
    // Discard the 0th element of input as we have took decisions for it in above steps
    ip.erase(ip.begin() + 0);
    
    changeCase(ip, op1);
    changeCase(ip, op2);
    
    return;
}

int main()
{
    string s = "ab";
    string output = "";
    
    changeCase(s, output);
    
    return 0;
}

/*
op:
ab
aB
Ab
AB
*/
