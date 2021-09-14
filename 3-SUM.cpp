// Triplet Sum in Array
// BRUTE ======================================== O(n^2) ==============================================================================================

int main()
{
    int a[] = {1, 4, 45, 6, 10, 8};
    int n = 6, x = 11;
    
    sort(a, a+n); // 1 4 6 8 10 45
    int k=n-1;
    int flag = 0;
    
    for(int i=0; i<n; i++){
        
        // Fix the 1st element i.e a[0] and then apply 2 pointer on (i+1) to (n-1) elements.
        int sum = x-a[i];  // sum = 13-1 =12
        int j = i+1;
        
        // Now find '12' using 2 pointer approach
        while(j < k){
            if((a[j]+a[k]) == sum){
                cout<<"Yes";
                flag = 1;
                break;
            }
            
            else if((a[j]+a[k]) > sum){
                k--;
            }
            
            else if((a[j]+a[k]) < sum){
                j++;
            }
        }
    }
    
    if(flag == 0) cout<<"No";
    
    return 0;
}
