
// === RECURSIVE ======================================================================================================================================================

int fibo(int n){
    // Base case - smallest sub-problem for which we already know the answer
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}

int main()
{
    int ans = fibo(5);
    cout<<ans;

    return 0;
}

// === Memoization DP ================================================================================================================================================

int fibo(int n, vector<int> &dpArray){
    // Base case - smallest sub-problem for which we already know the answer
    if(n==0) return 0;
    if(n==1) return 1;
    
    // if the answer is already computed, return it directly
    if(dpArray[n] != -1) return dpArray[n];
    
    // if the answer is not calculated, then calculate it and store it in dpArray
    int num = fibo(n-1, dpArray)+fibo(n-2, dpArray);
    dpArray[n] = num;
    return num;
}

int main()
{
    int n = 5;
    vector<int> arr(100, -1);
    cout<<fibo(5, arr);

    return 0;
}

// === Tabulation DP ================================================================================================================================================

// 1-D array
vector<int> dp;

int fiboBU(int n){
    vector<int> dp(n+1, 0);
    // Base case
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    return dp[n];
}

int main()
{
    cout<<fiboBU(6);

    return 0;
}
