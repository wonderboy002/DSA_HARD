#include<iostream>
#include<queue>
using namespace std;
void display(queue<int> q){
    cout<<"Your queue is : "<<endl;
    while (!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverse(queue<int> &q){
    if (q.empty()){
        return;
    }

    int temp=q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}
int main(){
queue<int> q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
q.push(60);
display(q);
reverse(q);
display(q); 
return 0;
}