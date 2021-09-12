int main()
{
    int a[] = {1, 2, 3, -4, -1, 4};
    int n = 6;
    
    sort(a, a+n); // -4 -1 1 2 3 4 
    vector<int> vec;
    int i=0, j=0;
    
    for(i=0; i<n; i++){
        if(a[i]<0) vec.push_back(a[i]);
        for(j=i+1; j<n; j++){
            if(a[j] > 0 ){
                vec.push_back(a[j]);
                //i+=i;
                break;
            }
        }
    }
    
    for(auto it: vec){
        cout<<it<<" ";
    }
    
    return 0;
}
