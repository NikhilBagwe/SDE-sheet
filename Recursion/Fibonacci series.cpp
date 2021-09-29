// =============================================================== Time Complexity: T(n) = T(n-1) + T(n-2) ===================================================================
// Just prints the nth fibonacci number

#include <iostream>
using namespace std;

int fibo(int n){
    if(n < 2){
        return n;
    }
    
    //int ans = fibo(n-1) + fibo(n-2);
    return fibo(n-1) + fibo(n-2);
}

int main()
{
    cout<<fibo(10);

    return 0;
}

// PRINT FIBONACCI NUMBERS UNTIL 'n' ========================================================================================================================

void fibo(int n){
    static int n1=0, n2=1, n3;
    if(n > 0){
        n3 = n1 + n2;
        n1 = n2;
        n2 = n3;
        cout<<n3<<" ";
        fibo(n-1);
    }
}

int main()
{
    int n = 0;
    cout<<"Enter the nth fibonacci number : ";
    cin>>n;
    cout<<0<<" "<<1<<" ";
    // (n-2) since two numbers are already printed 
    fibo(n-2);

    return 0;
}
