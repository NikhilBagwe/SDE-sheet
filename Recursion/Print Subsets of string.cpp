
void printSubset(string input, string output, int n){
    if(n >= input.size()){
        cout<<output<<endl;
        return;
    }
    
    // Not pick
    printSubset(input, output, n+1);
    
    // Pick
    output += input[n];
    printSubset(input, output, n+1);
    return;
}

int main()
{
    string s = "ab";
    printSubset(s, "", 0);

    return 0;
}
