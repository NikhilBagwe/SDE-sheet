void printTri(vector<int> &arr, int n){
    // Base condition
    if(n<1){
        return;
    }
    
    // Create an array and store the sum sum of consecutive elements
    vector<int> temp;
    
    // Storing the sum of consecutive elements into the array
    for(int i=0; i<n-1; i++){
        int x = arr[i] + arr[i+1];
        temp.push_back(x);
    }
    
    printTri(temp, n-1);
    
    // We are using backtracking here to print in reverse order i.e the last array with smaller size is printed first
    // If we cut and paste this for loop before line 17, the array with largest size is printed first.
    for(int i=0; i<n; i++){
        if(i == n-1){
            cout<<arr[i]<<" ";
        }
        else{
            cout<<arr[i]<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    vector<int> arr {1,2,3,4,5};
    int n = arr.size();
    printTri(arr, n);
    return 0;
}
