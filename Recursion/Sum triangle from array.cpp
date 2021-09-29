void printTri(vector<int> &arr, int n){
    if(n<1){
        return;
    }
    
    vector<int> temp;
    
    for(int i=0; i<n-1; i++){
        int x = arr[i] + arr[i+1];
        temp.push_back(x);
    }
    
    printTri(temp, n-1);
    
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
