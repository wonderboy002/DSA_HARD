#include<iostream>
#include<stack>
using namespace std;
void display(stack<int> st){
    while (!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(51);
    st.push(52);

    st.pop();
    st.pop();
    st.pop();
    cout<<"Your stack's given by : "<<endl;
    cout<<"size of the stack's given by : "<<st.size()<<endl;
    cout<<"Whether stack's empty : "<<st.empty()<<endl;
    display(st);
    return 0;
}