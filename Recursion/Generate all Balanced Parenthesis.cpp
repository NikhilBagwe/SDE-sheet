// Refer recurssive tree to understand the conditions

#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int open, int close, string op){
    // Base
    if(open == 0 && close == 0){
        cout<<op<<endl;
        return;
    }
    
    // Until you have open brackets keep them inserting bcoz if you insert close brackets first than you won't be able 
    // genearte a balanced parenthesis
    if(open != 0){
        string op1 = op;
        op1.push_back('(');
        generateParenthesis(open-1, close, op1);
    }
    
    // When close brackets are more than open, insert a close bracket 
    if(close > open){
        string op2 = op;
        op2.push_back(')');
        generateParenthesis(open, close-1, op2);
    }
    
    return;
}

int main()
{
    int open = 3;
    int close = 3;
    string op = "";
    generateParenthesis(open, close, op);

    return 0;
}
