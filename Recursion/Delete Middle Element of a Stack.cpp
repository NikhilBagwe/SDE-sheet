#include <bits/stdc++.h>
using namespace std;

void deleteMid(stack<int> &st, int n, int i){
    // Base - when we reach at the middle element, delete it 
    if(i == n){
        st.pop();
        return;
    }
    
    // Hypothesis - store the top element and increment the counter 'i'
    int temp = st.top();
    st.pop();
    i++;
    deleteMid(st, n, i);
    
    // Induction - insert the poped element back into stack
    st.push(temp);
    return;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    
    // stores the position at which the middle elemnent is located i.e 3
    int mid = st.size()/2;
    
    deleteMid(st, mid, 0);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
