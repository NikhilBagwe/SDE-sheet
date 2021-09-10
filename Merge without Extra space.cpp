// BRUTE - Normal merge sort for merging two sorted arrays ============ SC-O(n+m) =========

int main()
{
    int a1[] = {1, 3, 5, 7};
    int a2[] = {0, 2, 6, 8, 9};
    int n = 4, m =5;
    
    sort(a1, a1+n);
    sort(a2, a2+m);
    
    int temp[n+m];
    int i = 0, j = 0, k = 0;
    
    while(i<n && j<m){
        if(a1[i] > a2[j]){
            temp[k++] = a2[j++];
        }
        if(a1[i] < a2[j]){
            temp[k++] = a1[i++];
        }
    }
    
    while(i<n){
        temp[k++] = a1[i++];
    }
    
    while(j<m){
        temp[k++] = a2[j++];
    }
    
    for(int i = 0; i<n+m; i++){
        cout<<temp[i]<<" ";
    }

    return 0;
}
