/*
string str = "Microsoft"

Substring : Group of consecutive elements. Substring can also be a subsequence but vice versa is not possible.
eg : Mic, Micro, ros, etc

Subsequence : We can skip certain characters in subsequence.
eg: st, Miro, Mit, etc


*/

void subSequence(string input, string output, int index){
    // Base case
    if(index >= input.size()){
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    // including element
    output += input[index];
    subSequence(input, output, index+1);
    
    // Excluding element - remove the last element of output string
    output = output.substr(0, output.size()-1);
    subSequence(input, output, index+1);
}

int main()
{
    string s = "abc";
    
    subSequence(s, "", 0);

    return 0;
}
