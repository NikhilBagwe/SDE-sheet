// BRUTE ======================================================== TC: T(n) = T(n-1) + T(n-2) =====================================================================

int dearrange(int n){
    // Base cases
    if(n==1) return 0;
    if(n==2) return 1;
    
    // dearrangement formula
    return (n-1) * (dearrange(n-1) + dearrange(n-2));
    
}

int main()
{
    int num=4;
    
    cout<<"Count of Derangements is "<<dearrange(num);

    return 0;
}
