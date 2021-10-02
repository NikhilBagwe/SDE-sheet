#include <bits/stdc++.h>
using namespace std;

void insert(stack<int> &st, int num){
    // Base 
    if(st.size() == 0){
        st.push(num);
        return;
    }
    
    // Hypothesis
    int temp = st.top();
    st.pop();
    insert(st, num);
    
    // Induction
    st.push(temp);
    return;
}

void reverseStack(stack<int> &st){
    // When stack contains only 1 element, the element itself is reversed, sorted, increasing, decreasing 
    if(st.size() == 1){
        return;
    }
    
    int temp1 = st.top();
    st.pop();
    reverseStack(st);
    
    insert(st, temp1);
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
    
    reverseStack(st);

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
