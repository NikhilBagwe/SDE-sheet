// BRUTE ================================================== TC = O(nlogn) ==============================================================================

int main()
{
    int a[] = {2,6,1,9,4,5,3};
    int n = 7;
    
    sort(a, a+n);
    int val = 1, count = 0;
    
    for(int i=0; i<n; i++){
        if(a[i] == val){
            count++;
            val++;
        }
    }
    
    cout<<count;

    return 0;
}
