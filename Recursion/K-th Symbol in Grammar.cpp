// explanation -> https://leetcode.com/problems/k-th-symbol-in-grammar/discuss/938544/C%2B%2B-Recursive-Solution-with-diagrammatic-explanation

#include <bits/stdc++.h>
using namespace std;

/*
LOGIC :
For kthGrammar(4,6) = ans is 0
Representation :
    0 <- base case
    01
    0110 
    01101001 <- ans = row=4, col=6 -> 0

observation:
1. Size of each row is double of previous row.
2. For eg. at 3rd row '01' in '0110' is same as from 2nd row i.e until mid element of 3rd row, the elements are same as from prev row 
3. elements after mid of 4th row are compliment of 3rd row 

*/

// n -> row number, k -> column no.
int kthGrammar(int n, int k) {
    // Base case
    if(n==1, k==1) {
        return 0;
    }
    
    // Hypothesis
    int mid = pow(2, n-1) / 2; // mid = 4, 2 ,1
    
    // Induction
    if(k <= mid) return kthGrammar(n-1, k); // 2nd call-> (2, 1), 3rd call-> (1,1)
    return !kthGrammar(n-1, k-mid); // 1st call-> (3, 1)
}
    
int main()
{
    int ans = kthGrammar(4,6);
    cout<<ans;

    return 0;
}
