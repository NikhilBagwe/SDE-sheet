
#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int temp){
    if(st.empty() || st.top() <= temp){
        st.push(temp);
        return;
    }
    
    // Pop the top element from stack and store it, and call insert() again
    int val = st.top();
    st.pop();
    insert(st, temp);
    
    // Induction 
    st.push(val);
    return;
}

void sortStack(stack<int> &st){
    // Base - as 1 element is always sorted
    if(st.size() == 1) return;
    
    // Store the top element and than pop it and call sortStack() again
    int temp = st.top();
    st.pop();
    sortStack(st);
    
    // Induction
    insert(st, temp);
    return;
}


int main()
{
    stack<int> st;
    st.push(5);
    st.push(1);
    st.push(0);
    st.push(2);
    sortStack(st);
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
