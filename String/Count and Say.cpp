// Problem statement ======================================================================================================================================================

// Convert "22111342" into "2231131412" means  ->     22    111      3    4     2
//                                                  two 2 three 1  one 3 one 4 one 2  = 2231131412

int main()
{
    string s = "22111342"; // 2231131412
    
    int counter=0;
    string res = "";
    
    for(int i=0; i<s.length(); i++){
        counter++;
        // If you reach the end of string (to prevent out of bound error) OR next character is not equal to current character means the sequence is broken
        if(i == s.length() || s[i] != s[i+1]){
            // Add the count and the current character to the result string
            res = res + to_string(counter) + s[i];
            // Reset the counter
            counter=0;
        }
    }
    
    cout<<res;

    return 0;
}

// MAIN QUESTION ======================================================================================================================================================
// link = https://leetcode.com/problems/count-and-say/

// Our base condition is that if n==1 return "1", so here we can use recursion to find answer.

#include <bits/stdc++.h>
using namespace std;

/*
LOGIC:
1. For (n=1) = "1"
2. n=2 -> refer previous answer which is "1". So print its count first and then the character itself = "11"
3. n=3 -> from previous ans i.e "11" it converts into 'two 1' = "21"
4. n=4 -> from previous ans "21" it converts into "one 2 one 1" = "1211"
*/

string countAndSay(int n){
    if(n == 1) return "1";
    
    // Apply recursion
    string s = countAndSay(n-1);
    
    int counter=0;
    string res = "";
    
    for(int i=0; i<s.length(); i++){
        counter++;
        if(i == s.length() || s[i] != s[i+1]){
            res = res + to_string(counter) + s[i];
            counter=0;
        }
    }
    return res;
}

int main()
{
    string ans = countAndSay(4);
    cout<<ans;

    return 0;
}
