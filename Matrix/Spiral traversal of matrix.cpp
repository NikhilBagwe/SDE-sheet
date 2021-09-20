#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r = 4, c = 4;
    vector<vector<int>> matrix {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15,16}};
    
    vector<int> spiral;
    
    // Initialize the 4 pointers pointing to the 4 corners of the matrix
    int startRow = 0, endRow = r-1;
    int startColumn = 0, endColumn = c-1;
    
    while(startRow<=endRow && startColumn<=endColumn){  
        
        // Printing the first row 
        for(int i=startColumn; i<=endColumn; i++){
            spiral.push_back(matrix[startRow][i]);
        }
        startRow++;
        
        // Printing the last column 
        for(int i=startRow; i<=endRow; i++){
            spiral.push_back(matrix[i][endColumn]);
        }
        endColumn--;
        
        // Checking for out of bound error
        if(startRow <= endRow){
            // Printing the ending/last row 
            for(int i=endColumn; i>=startColumn; i--){
                spiral.push_back(matrix[endRow][i]);
            }
            endRow--;
        }
        
        if(startColumn <= endColumn){
            // Printing the first column 
            for(int i=endRow; i>=startRow; i--){
                spiral.push_back(matrix[i][startColumn]);
            }
            startColumn++;
        }
    }
    
    for(auto it : spiral){
        cout<<it<<" ";
    }

    return 0;
}
