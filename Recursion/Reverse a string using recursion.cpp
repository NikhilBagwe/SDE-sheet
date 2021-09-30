
void revString(vector<char>& s, int left, int right){
    if(left >= right){
        for(auto it: s){
            cout<<it<<" ";
        }
        return;
    }
    
    swap(s[left++], s[right--]);
    revString(s, left, right);
}

int main()
{
    vector<char> s {'h','e','l','l','o'};
    revString(s, 0, s.size()-1);

    return 0;
}
