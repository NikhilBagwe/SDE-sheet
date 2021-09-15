int main()
{
    int a[] = {3, 4, 1, 9, 56, 7, 9, 12}; 
    int n = 8, students = 5;     // students=m -> from question
    // int a[] = {7, 3, 2, 4, 9, 12, 56};
    // int n = 7, students = 3;
    
    sort(a, a+n);  // [1, 3, 4, 7, 9, 9, 12, 56]
    //                 i           j
    
    // points to the minimum and maximum values after sorting
    int i=0, j=students-1;
    int minDiff=INT_MAX;
    
    // We write (i+students < n) because if (i+students) becomes greater than 'n' our pointer 'j' will go out of bound.
    for(int i = 0; i+students < n; i++){
        if((a[j]-a[i]) < minDiff){
            minDiff = a[j]-a[i];
        }
        j++;
    }
    
    cout<<minDiff;

    return 0;
}
