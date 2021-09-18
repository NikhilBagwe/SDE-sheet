#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {111, 222, 333, 444, 555};
    int n = 5;
    // int a[] = {121,131,20};
    // int n = 3;
    
    // Traverse each elemnet of array
    for(int i=0; i<n; i++){
        // Convert the current elemnet into string
        string str = to_string(a[i]);
        
        // Pointers to start and end of string str
        int k=0;
        int j=str.length()-1;
        
        // Loop until (k<j), as the center element of a string needs not to be checked as it is always palindromic
        while(k<j){
            if(str[k] != str[j]){
                cout<<"Not palindromic";
                return 0;
            }
            k++;
            j--;
        }
    }
    
    cout<<"Palindromic";
    
    return 0;
}
