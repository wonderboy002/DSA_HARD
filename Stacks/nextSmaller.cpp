#include <bits/stdc++.h>
using namespace std;
void display(vector<int> arr)
{
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> nextSmaller(int *heights, int n)
{
    stack<int> m;
    vector<int> ans(n, 0);
    m.push(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (m.top() != n && heights[m.top()] > heights[i])
        {
            m.pop();
        }
        ans[i] = m.top();
        m.push(i);
    }
    return ans;
}

vector<int> prevSmaller(int *heights, int n)
{
    stack<int> m;
    vector<int> ans(n,0);
    m.push(-1);

    for (int i=0;i<n;i++){
        while (m.top()!=-1 && heights[m.top()]>heights[i]){
            m.pop();
        }
        ans[i]=m.top();
        m.push(i);
    }

    return ans;

}
int main()
{
    int arr[] = {2, 1, 5, 6, 2, 3};
    vector<int> smaller = nextSmaller(arr, 6);
    vector<int> smaller2 = prevSmaller(arr, 6);

    cout<<"next Smaller indices : "<<endl;
    display(smaller);
    cout<<"previous Smaller indices : "<<endl;
    display(smaller2);
    return 0;
}