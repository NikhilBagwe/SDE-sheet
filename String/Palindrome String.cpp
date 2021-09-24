// OPTIMAL ======================================================= TWO POINTER ===============================================================================================

int main()
{
    string s = "abbaa";
  
    int i=0, j=s.length() - 1;
	  int flag = 0;
	
    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
      
        // When string is not palindrome print 0
        else{
            cout<<0;
            flag = 1;
            break;
        }
    }
  
    // When string is palindrome print 1
    if(flag == 0) cout<<1;

    return 0;
}
