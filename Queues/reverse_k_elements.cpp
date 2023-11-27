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

void reverseK(queue<int> &q,int k){
    if (k==0){
        return;
    }
    int temp=q.front();
    q.pop();
    reverseK(q,k-1);

    q.push(temp);
}

void rearrange(queue<int> &q,int k){
    while (k--){
        q.push(q.front());
        q.pop();
    }
}
int main(){
queue<int> q;
q.push(10);
q.push(20);
q.push(30);
q.push(40);
q.push(50);
int k=2;
display(q);
reverseK(q,k);
rearrange(q,q.size()-k);
display(q); 
return 0;
}