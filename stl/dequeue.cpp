#include<iostream>
#include<deque>
using namespace std;
void display(deque<int> dq){
    cout<<"Your Deque is : "<<endl;
    while (!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<endl;
}
int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_front(100);
    dq.push_front(200);
    display(dq);

    dq.pop_back();
    dq.pop_back();
    dq.pop_front();
    display(dq);

    cout<<"Size of deque is : "<<dq.size()<<endl;
    cout<<"deque empty?? : "<<dq.empty()<<endl;
    return 0;
}