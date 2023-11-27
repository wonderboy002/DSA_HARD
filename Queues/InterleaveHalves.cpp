#include <iostream>
#include <queue>
using namespace std;
void display(queue<int> q)
{
    cout << "Your queue is : " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

queue<int> interleave(queue<int> q)
{
    queue<int> temp;
    int n = q.size() / 2;
    while (n--)
    {
        temp.push(q.front());
        q.pop();
    }

    cout<<"first half : "<<endl;
    display(temp);
    cout<<"second half : "<<endl;
    display(q);

    while (!temp.empty()){
        q.push(temp.front());
        temp.pop();
        q.push(q.front());
        q.pop();
    }
    return q;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    // display(q);
    queue<int> result=interleave(q);
    display(result);
    // display(q);
    return 0;
}