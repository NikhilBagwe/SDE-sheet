// METHOD 1 ==========================================================================================================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Helloo";
    
    reverse(str.begin(), str.end());
    
    for(auto it : str){
        cout<<it<<" ";
    }

    return 0;
}

// METHOD 2 ==================================================== TWO POINTER ====================================================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Helloo";
    int n = str.size();
    
    int i = 0, j = n-1;
    while(i <= j){
        swap(str[i++], str[j--]);
    }
    
    for(auto it : str){
        cout<<it<<" ";
    }

    return 0;
}
