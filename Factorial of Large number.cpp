#include <bits/stdc++.h>
using namespace std;

/*
ALGO:
eg: 5! = 1 x 2 x 3 x 4 x 5
1. Declare an vector and assign '1' at its 0th index as 1 is the least multiple of any number i.e we always start
   like 1*2*3*...*n 
   SIZE -> size of the vector 
2. Now run a loop from index=1, and keep multiplying elements from ind=1 to n with the vector[0] element until the
   the 'size' becomes 0 or no. becomes a double digit no. or until we get a carry. When the previously mentioned conditions
   are met, escape the loop and increment 'i'
3. In 1st iteration -> vector[0] = 1
      2nd iteration -> 2
      3rd iteration -> 6 
      4th iteration -> 24 [4 x 6=24]
      - Update vector[0] by '4' and put '2' in CARRY and we find them:
        CARRY -> 24%10 = 2,  VALUE -> 24/10 = 4 
4. Now we have to update the vector[0] by assigning CARRY to it and shifting the the contents of vector by 1.
   Assign CARRY back to 0 and size should be increased by 1 as we add elements to it. 
*/

int main()
{
    vector<int> fact;
    int size=0, carry=0;
    int n=4; // number whose factorial is to be found
    
    // Adding '1' at 0th index
    fact.push_back(1);
    
    // updating the size as we have added 1 element 
    size=1;
    
    // Declare a variable to traverse from 2 to n 
    int val = 2;
    
    // eg: n=5
    while(val <= n){  // 2 3 4 5
        // traverse the vector from right to left
        for(int i=size-1; i>=0; i--){
            // update value in vector
            int temp = fact[i]*val + carry;                             // 2  6  24  
            // store the last digit at index and add remaining to carry
            fact[i] = temp%10;                             // Remainder -> 2  6  4
            // update carry
            carry = temp/10;                               // quotient  -> 0  0  2
        }
        // If carry is not consumed i.e it is double digit, then insert carry digit by digit into vector
        while(carry != 0){                                // at 4th iteration -> 2 
            int a = carry%10;                             // 2
            // push value to front of vector
            fact.insert(fact.begin(),a); 
            carry /= 10;                                  //  0
            // since we inserted an elemnet the size of vector is increased by 1.
            size++;
        }
        val++;
    }
    
    for(auto it:fact){
        cout<<it<<" ";
    }

    return 0;
}
