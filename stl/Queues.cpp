#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> Q){
    cout<<"Your Queue is : "<<endl;
    while (!Q.empty()){
        cout<<Q.front()<<" ";
        Q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.pop();
    Q.pop();
    display(Q);
    cout<<"Size of Your Queue : "<<Q.size()<<endl;
    cout<<"Front of Your Queue : "<<Q.front()<<endl;
    cout<<"Rear of Your Queue : "<<Q.back()<<endl;
    return 0;
}