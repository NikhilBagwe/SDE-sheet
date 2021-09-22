// OPTIMAL =================================================== TC = O(n^2) , SC = O(n^2) ===================================================================================

int main()
{
    int r=3, c=3;
    vector<vector<int>> matrix {{1,2,3},
                                {4,5,6},
                                {7,8,9}};
    
    int n = matrix.size(); // 3 
    
    // Taking transpose of the matrix
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    // Reversing each row to get the 90 degree rotated matrix
    for(int i=0; i<n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
