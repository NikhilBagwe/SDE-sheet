
int findMin(vector<int> &arr, int n){
    // Base case -> as only 1 element is remaining in the array, return it.
    if(n==1){
        return arr[0];
    }
    
    // traverse the array recursively from the end 
    // call the function by passing the array of one size less from the end, i.e. from arr[0] to arr[n-1].
    // If we put max instead of min it will return the max element.
    return min(arr[n-1], findMin(arr, n-1));
}

int main()
{
    vector<int> arr {1, 4, 3, -5, -4, 8, 6};
    int n = arr.size();
    
    cout<<findMin(arr, n);

    return 0;
}
