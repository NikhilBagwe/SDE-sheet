// BRUTE ========================================================== SC = O(n+m) ==================================================================================
// Use merge sort and store the resultant array in temp array and then calculate the median

int main()
{
    int a1[] = {2, 4, 9, 12};
    int a2[] = {5, 6, 8, 13};
    int n = 5, m = 4;
    
    int temp[n+m];
    int i=0, j=0, k=0;
    
    while(i<n && j<m){
        if(a1[i] < a2[j]){
            temp[k++] = a1[i++];
        }
        
        else if(a1[i] > a2[j]){
            temp[k++] = a2[j++];
        }
    }
    
    while(i<n){
        temp[k++] = a1[i++];
    }
    
    while(j<n){
        temp[k++] = a2[j++];
    }
    
    for(int i=0; i<n+m; i++){
        cout<<temp[i]<<" ";
    }
    
    int ans = 0;
    int size1 = n+m;
    
    if(size1%2 == 0){
        int a = size1/2;
        int b = a - 1;
        ans = (temp[a]+temp[b])/2;
    }
    
    else{
        ans = temp[((size1+1)/2)-1];
    }
    
    cout<<"Median : "<<ans<<endl;

    return 0;
}

// OPTIMAL ========================================================================================================================================================

/*
ALGO:
1. We have to find such a cut in the that divides both the arrays with equal elemennts on both sides.

2. This conditions must be met : l1 <= r2 and l2 <= r1
   eg: a1[] = {2 4 | 9 12}
       a2[] = {5 6 | 8 13}
   l1=4, r1=9, l2=6, r2=8

3. In the beginning we will place the cut after the 1st element of arr1. So now in order to have equal elements on both 
   the sides we need to take 3 elements from arr2 as we only took 1 element from arr1.
       a1[] = {2 | 4  9 12}
       a2[] = {5 6 8 | 13}
    now l1=2, r1=4, l2=8, r2=13 -> Don't satisfy the condition as l2 > r2 so increase the cut by 1 i.e after 4.

4. Now on increasing the cut, the conditions are satisfied.
       a1[] = {2 4 | 9 12}
       a2[] = {5 6 | 8 13}

5. EVEN elements :
   Since the size of arrays is even we need to find the 3,4 element for median.
   3rd -> the max or largest element on the left side of cut 
   4th -> the min or smallest element on the right side of cut
   Formula -> (max(l1, l2) + min(r1, r2)) /2
              = (6 + 8)/2 = 7
              
6. ODD elements :
   Formula -> min(r1, r2) /2
   
7. For DIFFERENT size arrays, always apply binary search on small size array to avoid out of bound error.
*/
