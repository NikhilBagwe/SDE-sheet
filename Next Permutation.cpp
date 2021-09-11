#include <bits/stdc++.h>
using namespace std;

/*
THEORY:
- Lexiographically means the next smallest number greater than the given number.
  eg: given no. - 8, Lexiographically number - 9
      we can also have written 10,11,etc. but we have write the next no. following lexiographically condition

- Permutation means diff. arrangements of given numbers
  eg: [1,2,3] => [1 3 2] [2 1 3] [2 3 1] [3 1 2] [3 2 1] 
  
- Perform Permutation lexiographically means :
  Suppose [1 2 3] is given which means the given no. is -> 123, so the next greater Permutation lexiographically is 132 as 
  it follows the lexiographic condition.
  
- Lowest possible no. by Permutation(for our example ) : 123  -> Ascending order
  Highest possible no. by Permutation : 321 -> Descending order
  
ALGO:
eg: a[]=[1 3 5 4 2]

1. Linearily traverse from the back to find the ith element such that (a[i] < a[i+1]) i.e index-1 = 1 in our example.
-> IMP: There is always a increasing sequence from backwards.
   eg:      5
        3       4       <- increasing sequence is 2-4-5
     1              2    
   Thus we perform step 1 to find the index at which this breakdown takes place i.e index-1=1

2. Again perform a Linear traversal from back to find the index-2 having value greater than index 1 i.e a[1] = 3
   (a[index-2] > a[index-1]) -> index-2 = 3 i.e a[3] = 4
   Here we can also consider a[2]=5 as the number but a[3]=4 is the next lexiographic Permutation after '3'.
   
3. Swap values present at index-1 and index-2. -> [1 4 5 3 2]

4. Reverse everything present towards right of (index1 + 1) to last.  -> [1 4 2 3 5]

*/
