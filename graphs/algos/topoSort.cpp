#include <bits/stdc++.h>
using namespace std;

// Function to initialize the graph represented as an adjacency list
// adj: a 2D vector of integers representing the adjacency list
// m: an integer representing the number of edges in the graph
void init_graph(vector<int> adj[], int m)
{
    // Iterate through each edge in the graph
    while (m--)
    {
        int u, v;
        cout << "Enter the edge : " << endl;
        cin >> u >> v;
        // Add the edge to the adjacency list
        adj[u].push_back(v);
        // directed graph
    }
}

// Function to display the adjacency list
// adj: a 2D vector of integers representing the adjacency list
// n: an integer representing the number of vertices in the graph
void display(vector<int> adj[], int n)
{
    // Iterate through each vertex in the graph
    for (int i = 0; i < n; i++)
    {
        cout << "neighbours of vertex : " << i << endl;
        // Iterate through the vector at the corresponding index
        for (auto n : adj[i])
        {
            cout << n << " ";
        }
        cout << endl;
    }
}

// Function to perform breadth-first search (BFS) traversal
// adj: a 2D vector of integers representing the adjacency list
// n: an integer representing the number of vertices in the graph
// start: an integer representing the starting vertex for BFS
void topoSort(int src, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{
    visited[src] = true;
    for (auto adjNode : adj[src])
    {
        if (!visited[adjNode])
        {
            topoSort(adjNode, adj, visited, st);
        }
    }
    st.push(src);
}

int main()
{
    int n;
    cout << "Enter the number of vertices : " << endl;
    cin >> n;

    // Initialize the adjacency list
    vector<int> adj[n];

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    // Initialize the graph
    init_graph(adj, m);
    cout << "adjacency list given by : " << endl;
    display(adj, n);

    stack<int> st;
    vector<bool> visited(n, false);

    cout << "The topological sort of the given graph is : " << endl;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {

            topoSort(i, adj, visited, st);
        }
    }


    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}