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
