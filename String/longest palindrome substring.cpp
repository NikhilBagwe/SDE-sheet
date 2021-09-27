#include <bits/stdc++.h>
using namespace std;

/*
ALGO:
1. In a nutshell you iterate over the string, for each character you TRY expanding it as a palindrome by adding a char to the left and to the right.
2. If both characters are the same then the expansion is possible and then you try another expansion and so on until it's not possible.
3. Now check if the length of the max possible expansion is greater than max and update it. 
4. Then do the same for the next character and so on.

eg: 
s = 'ababc'
max = 1

'a' => no possible expansions
'b' => a b a => palindrome ('a' == 'a'), update max = 3 => no more possible expansions
'a' => b a b => palindrome ('b' == 'b'), will not update max since 3 is not greater than max => ab a bc => not a plaindrome ('a' != 'c')

*/

int main()
{
    string s = "ababc";
    
    if(s.size() == 1){
        cout<<1;
        return 0;
    }
    
    // initialize the start and end pointers for string
    int min_left = 0;
    int max_right = s.size() - 1;
    // every character is a palindrome itself, so the max lenght will be atleast 1 
    int max_length = 1;
    
    for(int mid=0; mid<s.size(); ){
        int left = mid;
        int right = mid;
        
        // skipping duplicate characters
        while(right<max_right && s[right]==s[right+1]){
            right++;
        }
        
        // For next iteration 
        mid = right+1;
        
        // Expand the selection as long as it is palindrome
        while(right<max_right && left>0 && s[right+1]==s[left-1]){
            right++;
            left--;
        }
        
        // Store the new maximum length of palindrome
        int new_len = right-left + 1;
        
        if(new_len > max_length){
            min_left = left;
            max_length = new_len;
        }
        
    }
    
    cout<<s.substr(min_left, max_length);

    return 0;
}
