int find_median(vector<int> v)
{
    // Sort the array to arrange everything in ascending order
    sort(v.begin(), v.end());
    int n=v.size(), ans=0;

    // When length of array is even, average of two middle numbers gives the median
    // eg. [30 56 67 79]
    if(n%2 == 0){
        int mid = n/2; // mid=67
        int prev_mid = mid-1; // prev_mid=56
        ans = (v[mid] + v[prev_mid])/2;
    }

    // When array length is odd
    else{
        ans = v[((n+1)/2)-1];
    }

    return ans;
}
