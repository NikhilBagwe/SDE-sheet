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
