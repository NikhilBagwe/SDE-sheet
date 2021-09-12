int main()
{
    int A[] = {1, 5, 10, 20, 40, 80};
    int B[] = {6, 7, 20, 80, 100};
    int C[] = {3, 4, 15, 20, 30, 70, 80, 120};
    
    int n1=6, n2=5, n3=8;
    
    vector<int> common;
    int i=0, j=0, k=0;
    
    // to avoid pointers from going out of bound of arrays
    while(i<n1 && j<n2 && k<n3){
        
        // iterate the 1st and 2nd array until you find the common element between them.
        if(A[i] > B[j]) j++;
        else if(A[i] < B[j]) i++;
        
        // After finding the common element in 1st and 2nd arr, traverse the 3rd arr to check whether the common
        // element is present in 3rd arr also.
        else{
            // checking for duplicacy
            if(i>0 && A[i] == A[i-1]){
               i++;
               continue;
            }
            
            // find the common element in 3rd arr 
            while(k<n3 && C[k]<B[j]) k++;
            // After finding the common element, push it into the vector
            if(k<n3 && C[k] == B[j]){
                common.push_back(C[k]);
            }
            // Move to next element
            i++, j++;
        }
    }
    
    for(auto it: common){
        cout<<it<<" ";
    }

    return 0;
}
