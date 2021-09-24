#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "XY";
    string s2 = "12";
    // In the result, the order of s1 and s2 should not be disturbed i.e 'Y' should only come after 'X'.
    string res = "X12Y"; // Valid answers -> X1Y2, XY12, X12Y  || Non-Valid ans = X21Y, Y12X
    
    // Store the length all strings
    int len1 = s1.length();
    int len2 = s2.length();
    int len3 = res.length();
    
    if(len1+len2 != len3){
        cout<<"No";
    }
  
    else{
        int flag = 0;
        // 3 pointers pointing to the 1st element of each string 
        int i=0, j=0, k=0;
        
        // Compare s1 and s2 elements with elements of res.
        while(k < len3){
            
            // Compare current s1 element with current res element.
            if(i<len1 && s1[i] == res[k]) i++;
            
            // Compare current s2 element with current res element.
            else if(j<len2 && s2[j]==res[k]) j++;
            
            // If the above conditions won't execute means the element is absent in 'res' or it is present in wrong order so exit the loop.
            else{
                flag = 1;
                break;
            }
            k++;
        }
        
        // If the i and j have not reached the last element of s1 & s2 it means elements are not present in res or are present in wrong order.
        if(i<len1 || j<len2) cout<<"No";
        
        if(flag == 0) cout<<"Yes";
    }

    return 0;
}
