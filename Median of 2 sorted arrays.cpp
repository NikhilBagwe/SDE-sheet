// BRUTE ========================================================== SC = O(n+m) ==================================================================================
// Use merge sort and store the resultant array in temp array and then calculate the median

int main()
{
    int a1[] = {2, 4, 9, 12};
    int a2[] = {5, 6, 8, 13};
    int n = 5, m = 4;
    
    int temp[n+m];
    int i=0, j=0, k=0;
    
    while(i<n && j<m){
        if(a1[i] < a2[j]){
            temp[k++] = a1[i++];
        }
        
        else if(a1[i] > a2[j]){
            temp[k++] = a2[j++];
        }
    }
    
    while(i<n){
        temp[k++] = a1[i++];
    }
    
    while(j<n){
        temp[k++] = a2[j++];
    }
    
    for(int i=0; i<n+m; i++){
        cout<<temp[i]<<" ";
    }
    
    int ans = 0;
    int size1 = n+m;
    
    if(size1%2 == 0){
        int a = size1/2;
        int b = a - 1;
        ans = (temp[a]+temp[b])/2;
    }
    
    else{
        ans = temp[((size1+1)/2)-1];
    }
    
    cout<<"Median : "<<ans<<endl;

    return 0;
}
