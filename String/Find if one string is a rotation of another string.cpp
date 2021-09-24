// BRUTE ==================================================================================================================================================

int main()
{
    string s1 = "abcd", s2 = "bcda";
    
    // Store the length of both strings
    int len1 = s1.length();
    int len2 = s2.length();
    
    if(len1 != len2){
        cout<<"No";
    }
    else{
        // Add the 1st strings twice and store it in temp and check whether s2 is present as sub-string in it or not
        string temp = s1 + s1;
        // string::npos is static member with value as the highest possible for the size_t 
        // string::npos = -1
        if(temp.find(s2) != string::npos){
            cout<<"Yes";
        }
        else cout<<"No";
    }

    return 0;
}
