// TC = O(n^2)  ,  SC = O(n^2)
// link = https://practice.geeksforgeeks.org/problems/sorted-matrix2333/1#

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat) {
        // code here
        vector<int> temp;
        // Store the elements of matrix into an temp vector
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                temp.push_back(mat[i][j]);
            }
        }
        
        // Sort the vector
        sort(temp.begin(), temp.end());
      
        // Initialize a pointer to the vector storing sorted elements of matrix
        int ptr=0;
      
        // Now insert the sorted elements from vector back into the matrix and keep incrementing the pointer
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mat[i][j] = temp[ptr++];
            }
        }
        
        return mat;
    }
};
