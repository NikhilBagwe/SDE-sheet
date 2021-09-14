// video link -> https://www.youtube.com/watch?v=YAWRyWJalM0
// HARD

int main()
{
    int a[] = {10, 22, 5, 75, 65, 80};
    int n = 6;
    
    // Profit1 is what we gain after 1 transaction 
    int profit1 = 0;
    int minPrice1 = INT_MAX;
    
    // Profit2 is what we gain after both translations
    int profit2 = 0;
    int minPrice2 = INT_MAX;
    
    for(int i=0; i<n; i++){
        minPrice1 = min(minPrice1, a[i]);            //  10  10
        profit1 = max(profit1, a[i]-minPrice1);      //  0   12
        
        minPrice2 = min(minPrice2, a[i]-profit1);    //  10  10
        profit2 = max(profit2, a[i]-minPrice2);      //  0   12
        
        cout<<minPrice1<<" "<<profit1<<" "<<minPrice2<<" "<<profit2<<endl;
    }

    cout<<profit2;
    
    return 0;
}
