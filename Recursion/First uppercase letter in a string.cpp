
#include <bits/stdc++.h>
using namespace std;

void findCapital(string s, int n){
    if(isupper(s[n])){
        cout<<s[n]<<" at index: "<<n;
        return;
    }
  
    // Base case -> when you reach the last element and still don't find a capital letter.
    else if(n==0){
        cout<<"No capital element present";
        return;
    }
    
    // traversing the string backwards from the end 
    findCapital(s, n-1);
}

int main()
{
    string s = "geekgeJek";
    int n = s.length()-1;
    findCapital(s, n);

    return 0;
}
