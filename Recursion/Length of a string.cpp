
int stringLen(string s, int n){
    if(s[n]) n++;
    else return n;
    
    return stringLen(s, n);
}

int main()
{
    string s = "GEEKSFORGEEKS";
    int len = stringLen(s, 0);
    cout<<len;

    return 0;
}
