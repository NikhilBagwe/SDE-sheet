
void revString(vector<int> arr, int i, int j){
    // Base case 
    if(i>j){
        for(auto it: arr){
            cout<<it<<" ";
        }
        return;
    }
    
    swap(arr[i], arr[j]);
    // Two pointer approach
    revString(arr, i+1, j-1);
}

int main()
{
    vector<int> s {1,2,3,4,5};
    int n = s.size()-1;
    int i=0, j=n;
    
    revString(s, i, j);

    return 0;
}
