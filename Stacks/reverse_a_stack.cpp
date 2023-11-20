#include <bits/stdc++.h>
using namespace std;
void display(stack<int> st)
{
    cout << "Stack is : " << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout<<endl;
}
void insertBottom(stack<int> &st, int x)
{
    if (st.empty())
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertBottom(st, x);
    st.push(temp);
}

void reverse(stack<int> &s, int n)
{
    if (s.empty()){
       return;
    }

    int temp=s.top();
    s.pop();
    reverse(s,n);
    insertBottom(s,temp);
}

int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(130);
    st.push(120);
    st.push(250);
    st.push(15550);
    st.push(1501);
    display(st);

    reverse(st, st.size() - 1);
    display(st);

    return 0;
}