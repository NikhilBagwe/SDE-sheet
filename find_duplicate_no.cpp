// Brute approach - Sort the array and linearly traverse to find the duplicate no. at a[i] and a[i+1]  =========== O(nlogn) ========================

int main()
{
    int a[]={1,3,4,2,2};
    int n = 5;
    sort(a, a+n);
    
    for(int i=0; i<n; i++){
        if(a[i] == a[i+1]){
            cout<<a[i];
        }
    }
    
    return 0;
}

// Better - Create a frequency array of size n and linearly traverse the given array and perform HASHING  =============== TC = O(n), SC = O(n) ======================

int main()
{
    int a[]={1,3,4,2,2};
    int n = 5;
    int temp[n];
    
    for(int i=0; i<n; i++){
        temp[a[i]]++;
    }
    
    for(int i=0; i<n; i++){
        if(temp[a[i]] > 1){
            cout<<a[i];
            break;
        }
    }
    
    return 0;
}


















