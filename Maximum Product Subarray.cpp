// BRUTE ============================================================================================================================================================
// Fails for certain edge cases like a[]={-8 5 3 1 6} -> expected o/p=90, our o/p = 1

int main()
{
    int a[] = {2, 3, 4, 5, -1, 0};
    int n = 6;
    
    int maxProd=1, curProd=1;
    
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            curProd = 1;
            continue;
        }
        curProd *= a[i];
        
        if(curProd > maxProd){
            maxProd = curProd;
        }
        
    }
    cout<<maxProd;
    return 0;
}
