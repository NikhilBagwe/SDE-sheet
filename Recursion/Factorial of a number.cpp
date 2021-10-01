
int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}

int main()
{
    int n = fact(7);
    cout<<n;

    return 0;
}
