#include<bits/stdc++.h>
using namespace std;
void display(int *adj[],int n){
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void initialiseGraph(int *adj[],int m){
    while (m--){
        int u,v;
        //1 means there exists edge bw nodes u and v
        cout<<"Enter the edge"<<endl;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
}
int main(){
int n,m;
cout<<"Enter the number of vertices and edges : "<<endl;
cin>>n>>m;

int *adj[n+1];
//matrix of size nodesxnodes
for (int i=0;i<n+1;i++){
    adj[i]=new int [n+1];
    for (int j=0;j<n+1;j++){
        adj[i][j]=0;
    }
}

initialiseGraph(adj,m);
display(adj,n+1);
return 0;
}