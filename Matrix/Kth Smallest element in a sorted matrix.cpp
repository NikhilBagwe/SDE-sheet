// BRUTE =============================================================================================================================================

int main()
{
    vector<vector<int>> mat {{16, 28, 60, 64},
                             {22, 41, 63, 91},
                             {27, 50, 87, 93},
                             {36, 78, 87, 94 }};
                           
    int k=3, n=mat.size();
    vector<int> temp;
    
    // Store all elements of the matrix into a temp 1-D array
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(mat[i][j]);
        }
    }
    
    // Sort the array
    sort(temp.begin(), temp.end());
    
    // Print the [k-1] element
    cout<<temp[k-1];

    return 0;
}

// OPTIMAL ========================================================================================================================================================

/*
ALGO:
eg: {{1  5  9 }
     {10 11 13}
     {12 13 15}}
1. Since the matrix is row and column wise sorted our range is 1 to 15.
2. So we can apply nested binary search 
*/

int main()
{
    vector<vector<int>> mat {{16, 28, 60, 64},
                             {22, 41, 63, 91},
                             {27, 50, 87, 93},
                             {36, 78, 87, 94 }};
                           
    int k=3, n=mat.size();
    
    int r = mat.size();
    int c = mat[0].size();
    
    // Defining the range as startVal and endVal i.e the 1st element and last element of matrix
    int startVal = mat[0][0];
    int endVal = mat[r-1][c-1];
    int midVal = 0;

    while(startVal <= endVal){
        // Range based formula to find the mid element for binary search
        midVal = (startVal+endVal)/2;
        
        // 'ans' will store the count of elements that are less than or equal to midVal in the whole matrix
        int ans = 0;
        // Traversing the matrix row-wise
        for(int i=0; i<r; i++){
            
            // applying binary search on each row 
            int lo = 0, hi = c-1, mid = 0;
            while(lo <= hi){
                // Index based formula to find the mid element for binary search
                mid = lo + (hi-lo) / 2;
                if(mat[i][mid] <= midVal){
                    lo = mid + 1;
                }
                else{
                    hi = mid - 1;
                }
            }
            // 'lo' stores how many values are <= midVal in the current row on which binary search is applied and that value is added to 'ans' which stores the total count of
            // elements that are <= midVal in all rows i.e the whole matrix.
            ans += lo;
            cout<<ans<<endl;
        }
        
        if(ans < k) startVal = midVal + 1;
        else endVal = midVal - 1;
    }
    
    cout<<startVal;
    
    return 0;
}
