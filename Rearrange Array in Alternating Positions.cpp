// BRUTE ======================================= The order is not maintained for other test cases =========== SC=O(n) ===========================================

int main()
{
    int arr[] = {1, 2, 3, -4, -1, 4};
    int n = 6, mid=0;
    
    sort(arr, arr+n); // [-4, -1, 1, 2, 3, 4]
    
    for(int i=0; i<n; i++){
        if(arr[i] > 0){
            mid = i;
            break;
        }
    }
    
    vector<int> temp;
    
    int i=0, j=mid;
    while(i<mid && j<n){
        temp.push_back(arr[i]);
        temp.push_back(arr[j]);
        i++, j++;
    }
    
    while(j<n){
        temp.push_back(arr[j]);
        j++;
    }
    
    for(auto it: temp){
        cout<<it<<" ";
    }

    return 0;
}
