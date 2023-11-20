#include <bits/stdc++.h>
using namespace std;
void display(stack<int> s)
{
    cout << "Your stack is : " << endl;
    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
}

void insertSorted(stack<int> &s, int x)
{
    if (s.empty() || x > s.top())
    {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    insertSorted(s, x);
    s.push(temp);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    display(s);

    int x;
    cout << "enter the element to insert " << endl;
    cin >> x;
    insertSorted(s, x);
    display(s);
    return 0;
}