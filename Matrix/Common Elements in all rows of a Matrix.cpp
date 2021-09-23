
/*
ALGO:
1. Store all elemnts of 1st row into the map.

2. Start traversing the matrix from 2nd row and when you encounter a similar element that is present in the map
   - Check that its 'frequency == row number' and then only increment its frequency by 1. This prevents from adding
     same duplicate elements in the row(eg. Check 3rd row, 8 is repeated) into the map as our aim is to check whether a certain element is present in all the 
     rows of matrix , not how many times it is present throughout the matrix.

3. Atlast when you reach the last iteration i.e last row , check which element's frequency is r-1 and print it. 
*/

int main()
{
    vector<vector<int>> mat {{1, 2, 1, 4, 8},
                             {3, 7, 8, 2, 1},
                             {8, 7, 2, 8, 1},
                             {8, 1, 2, 7, 9}};
                             
    int r = mat.size();
    int c = mat[0].size();
    
    map<int, int> mp;
    
    // Store the frequency of all elemnts of the 1st row
    for(int i=0; i<c; i++){
        mp[mat[0][i]]++;
    }
    
    // Start traversing the matrix from 2nd row.
    for(int i=1; i<r; i++){
        for(int j=0; j<c; j++){
            
            // Check if the current element is already present in the map && if it is present than
            // check if its 'key value == current row number' to avoid duplicacy and then increase its frequency
            if(mp.count(mat[i][j]) && mp[mat[i][j]] == i){
                    mp[mat[i][j]]++;
            }
            
            // Check if we are on the last row or not && element is present in map && the element's freq == 4 i.e total no. of rows
            if(i == r-1 && mp.count(mat[i][j]) && mp[mat[i][j]] == r){
                cout<<mat[i][j]<<" "<<mp[mat[i][j]]<<"  ";
            }
        }
    }

    return 0;
}
