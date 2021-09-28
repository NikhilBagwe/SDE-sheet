#include <iostream>
using namespace std;

void printNum(int n){
    if(n==1){
        cout<<1;
        return;
    }
  
    // Print the current passed number
    cout<<n<<" ";
    // Call printNum by passing (current number-1) into it.
    printNum(n-1);
}

int main()
{
    printNum(10);

    return 0;
}
