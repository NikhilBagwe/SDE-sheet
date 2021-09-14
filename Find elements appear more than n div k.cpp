// BRUTE ======================================================================= TC = O(n) , SC = O(n) ===================================================================
// link = https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/
int main()
{
    int a[] = {3, 1, 2, 2, 1, 2, 3, 3};
    int n = 8, k=4;
    
    map<int, int> mp;
    int count = n/k;
    
    // store the frequency of each element in the map 
    for(int i=0; i<n; i++){
        mp[a[i]]++;
    }
    
    int num = 0;
    
    cout<<"Elements that appear more than n/k: ";
    for(int i=0; i<mp.size(); i++){
        if(mp[i] > count){
            num++;
            // Prints the element that appears more then n/k times
            cout<<i<<" ";
        }
    }
    
    cout<<endl;
    cout<<"Total : "<<num;
    
    return 0;
}
