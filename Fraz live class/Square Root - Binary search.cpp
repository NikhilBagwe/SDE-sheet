// link = https://www.codingninjas.com/codestudio/problems/square-root-integral_893351?leftPanelTab=1

// BRUTE =========================================================== O(N) =======================================================================

int sqrtN(long long int N)
{
    if(N==0) return 0;
  
    // Basic Linear Search
    for(long long int i=0; i<=N; i++){
        if(i*i == N) return i;
        if(i*i > N) return i-1;
    }
  
    return -1;
}

// OPTIMAL ====================================================================================================================================

int sqrtN(long long int n)
{
    if(n==0) return 0;
    
    // 1e8 => 10^8
    int s=1, e=1e8, ans=0;
    
    while(s<=e){
        long long int mid = s+(e-s)/2;
        
        if(mid*mid == n){
            return mid;
        }
      
        // the current 'mid' could be a possible answer(eg. if n=20, then its sq. root is 4.47, but we have to return 4) so store it in 'mid' and decrease the search space
        else if(mid*mid < n){
            s=mid+1;
            ans=mid;
        } 
      
        else e=mid-1;
    }
    return ans;
}
