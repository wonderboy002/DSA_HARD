#include <bits/stdc++.h>
using namespace std;
void display(stack<int> st)
{
    cout << "Stack is : " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
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
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(130);
    st.push(150);
    display(st);
    int x;
    cout << "enter element to push" << endl;
    cin >> x;

    insertBottom(st, x);
    display(st);
    return 0;
}