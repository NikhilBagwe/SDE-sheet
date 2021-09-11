// BRUTE ================= O(n^2) ===============================================

int main()
{
    int a[] = {2, 4, 1, 3, 5};
    int n = 5;
    int inv = 0;
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] > a[j]){
                inv++;
                cout<<"["<<a[i]<<" "<<a[j]<<"] ";
            }
        }
    }
    
    cout<<endl;
    cout<<inv;

    return 0;
}
