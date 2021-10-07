#include <bits/stdc++.h>
using namespace std;

void stringPermute(string input, int left, int right){
    if(left == right){
        cout<<input<<endl;
        return;
    }
    else{
        for(int i=left; i<=right; i++){
            swap(input[i], input[left]);
          
            // move the left pointer to next character.
            stringPermute(input, left+1, right);
            
            // backtracking - as you have swapped the string before, you have to bring it back to its original form in order
            // to perform further operations.
            swap(input[i], input[left]);
        }
    }
}

int main()
{
    string ip = "ABC";
    int l = 0;
    int r = ip.size()-1;
    stringPermute(ip, l, r);

    return 0;
}
