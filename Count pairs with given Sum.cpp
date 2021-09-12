// BRUTE ========================================================================================================================================

int main()
{
    int a[] = {1, 5, 7, 1};
    int n = 4, k = 6;
    int count = 0;
    
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i+1; j<n; j++){
            sum = a[i] + a[j];
            if(sum == k){
                count++;
            }
        }
    }
    
    cout<<count;

    return 0;
}

// BETTER ============================================================== TWO POINTER APPROACH  ===============================================================

int main()
{
    int a[] = {1, 5, 7, 1};
    int n = 4, target = 6;
    
    int count = 0, sum=0;
    int i=0, j=n-1;
    
    // sort the array
    sort(a, a+n); // 1 1 5 7
    
    while(i < j){
        sum = a[i] + a[j];
        
        if(sum == target){
            count++;
            i++;
        }
        
        else if(sum > target){
            j--;
        }
        
        else if(sum < target){
            i++;
        }
    }
    
    cout<<count;

    return 0;
}


