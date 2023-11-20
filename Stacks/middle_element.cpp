#include <bits/stdc++.h>
using namespace std;
//gfg mein bottom based indexing hai toh middle humesha n/2+1 hoga 
void display(stack<int> st)
{
    cout << "Stack is : " << endl;
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

int find_middle(stack<int> &st, int pos)
{
    if (pos==1){
        int ans=st.top();
        st.pop();
        return ans;
    }

    int temp=st.top();
    st.pop();
    int result=find_middle(st,pos-1);

    st.push(temp);
    return result;
}
int main()
{
    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    display(st);

    int n = st.size();
    int pos = n % 2 == 0 ? n / 2 : (n / 2) + 1;
    int middle = find_middle(st, pos);

    cout << "middle element is : " << middle << endl;
    display(st);
    return 0;
}