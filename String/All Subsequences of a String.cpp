/*
string str = "Microsoft"

Substring : Group of consecutive elements. Substring can also be a subsequence but vice versa is not possible.
eg : Mic, Micro, ros, etc

Subsequence : We can skip certain characters in subsequence.
eg: st, Miro, Mit, etc
  Formula = 2 ^ (length of string)

*/

void subSequence(string input, string output, int index){
    // Base case - when we reach to end of the string, ouput the subsequence which is stored in 'output' string
    if(index >= input.size()){
        for(int i=0; i<output.size(); i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    // Excluding element - remove the last element of output string
    subSequence(input, output, index+1);
    //           (abc,     "",       1)
    //           (abc,     "",       2) -> goes to line 30 and adds "c" to output
    //           (abc,     "",       3) -> prints empty space "" ,since o/p is empty and (index == input.size()) and returns to prev call
    
    // including element - add the element to the output and send it into recursion
    output += input[index];
    subSequence(input, output, index+1);
    //           (abc,    "c",       3) -> prints "c" as (index == input.size())
    
    // Excluding element - Here the output will be printed upside down otherwise line 23,24 are same as line 31,32
    //output = output.substr(0, output.size()-1);
    //subSequence(input, output, index+1);
}

int main()
{
    string s = "abc";
    
    subSequence(s, "", 0);

    return 0;
}
