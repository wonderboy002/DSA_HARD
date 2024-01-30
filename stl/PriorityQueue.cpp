#include<iostream>
#include<queue>
using namespace std;
int main(){
// priority_queue<int> Q;
// Q.push(10);
// Q.push(240);
// Q.push(24);
// Q.push(25);
// Q.push(21);
// cout<<Q.top()<<endl;
// Q.pop();
// Q.pop();
// cout<<Q.top()<<endl;
// Q.pop();
// cout<<Q.top()<<endl;

// cout<<Q.size()<<endl;
// if (Q.empty()){
//     cout<<"Queue empty : "<<endl;
// }
// else {
//     cout<<"Queue non empty : "<<endl;
// }

//max heap

//min heap

priority_queue<int,vector<int>,greater<int>> Q;
Q.push(10);
Q.push(20);
Q.push(30);
Q.push(50);
Q.push(90);

cout<<Q.top()<<endl;
Q.pop();
Q.pop();
cout<<Q.top()<<endl;

if (Q.empty()){
    cout<<"Queue empty : "<<endl;
}
else {
    cout<<"Queue non empty : "<<endl;
}

return 0;
}