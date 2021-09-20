// BRUTE ===========================================================================================================================================================

int main()
{
    int r = 4, c = 4;
    vector<vector<int>> matrix {{1, 2, 3, 4},
                                {5, 6, 7, 8},
                                {9, 10, 11, 12},
                                {13, 14, 15,16}};
    
    int flag = 0, target = 23;
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == target){
                cout<<"Element Present";
                flag = 1;
                break;
            }
        }
    }
    
    if(flag == 0) cout<<"Element absent";

    return 0;
}

// OPTIMAL  =============================================================== TC = O(n+logm) =============================================================================

int main()
{
    int r = 3, c = 3;
    vector<vector<int>> matrix {{1, 3, 5, 7},
                                {10, 11, 16, 20},
                                {23, 30, 34, 50}};
    
    int flag = 0, target = 23;
    
    // Iterate over each row and apply binary search on them
    for(int i=0; i<r; i++){
        // binary search
        int start=0, end=r-1, mid=0;
        while(start <= end){
            mid = (start+end)/2;
            
            if(matrix[i][mid] == target){
                cout<<"Element present at index : "<<i<<" "<<mid;
                flag = 1;
                break;
            }
            
            else if(matrix[i][mid] > target){
                end = mid-1;
            }
            
            else{
                start = mid+1;
            }
        }
    }
    
    if(flag == 0) cout<<"Element absent";

    return 0;
}
