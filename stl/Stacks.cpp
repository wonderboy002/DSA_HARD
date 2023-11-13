#include<iostream>
#include<stack>
using namespace std;
int main(){
stack<int> s;
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(50);
cout<<"size of stack is : "<<s.size()<<endl;

cout<<"stack is empty :: "<<s.empty()<<endl;
while (!s.empty()){
    cout<<s.top()<<endl;
    s.pop();
}

cout<<"Stack is empty :: "<<s.empty()<<endl;
return 0;
}