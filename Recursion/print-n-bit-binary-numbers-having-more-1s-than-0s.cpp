
//https://practice.geeksforgeeks.org/problems/print-n-bit-binary-numbers-having-more-1s-than-0s0252/1

#include <bits/stdc++.h>
using namespace std;

void printPrefix(int ones_count, int zeroes_count, int n, string op){
    if(n == 0){
        cout<<op<<endl;
        return;
    }
    
    // Choice 1 - select '1' as we have to satisfy the condition of (no.of ones > no.of zeroes)
    // Based on recurrsive tree -> One's choice is always available to us but Zero's choice is not always available 
    string op1 = op;
    op1.push_back('1');
    printPrefix(ones_count+1, zeroes_count, n-1, op1);
    
    // Choice 2 - select '0' 
    //Based on recurrsive tree -> Zero's choice is available when (ones_count > zeroes_count) 
    if(ones_count > zeroes_count){
        string op2 = op;
        op2.push_back('0');
        printPrefix(ones_count, zeroes_count+1, n-1, op2);
    }
    
    return;
}

int main()
{
    int n = 3;
    string op = "";
    int ones_count = 0;
    int zeroes_count = 0;
  
    printPrefix(ones_count, zeroes_count, n, op);

    return 0;
}
