// OPTIMAL ==================================================================== TC = O(n * logm) =======================================================================
// n -> rows, m -> columns
/*
LOGIC :
1. Since all rows are sorted, we can apply binary search on each row.
2. We will keep a track of when do we get the minimum 'lo' index as we know everything beyond it is 1.
3. In our example the 'ans' becomes 0 i.e 0th element and all elements after it are 1 in the last row. So it is the
   row with maximum 1s in it.
   
- Disadvantage:
Rows containing all zeroes will also be checked unnecessarily wasting time.
*/

int main()
{
    int r = 4, c = 4;
    vector<vector<int>> matrix {{0, 0, 0, 1},
                                {0, 0, 0, 1},
                                {0, 1, 1, 1},
                                {1, 1, 1, 1}};
    
    int ans = INT_MAX, row=0;                            
    for(int i=0; i<r; i++){
        int lo=0, hi=c-1, mid=0;
        
        // Binary search on each row
        while(lo <= hi){
            mid = lo + (hi-lo) / 2;
            
            // Check whether the number before(or towards the right side of) matrix[i][mid] is also 1 or not so we decrease the search space 
            if(matrix[i][mid] == 1){
                hi = mid - 1;
            }
            
            // To check whether 1 is present or not to the right side of matrix[i][mid]
            if(matrix[i][mid] == 0){
                lo = mid + 1;
            }
        }
        
        if(lo < ans){
            ans = lo;
            row = i;
        }
    }
    cout<<row<<" "<<ans;
    return 0;
}
