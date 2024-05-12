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
        adj[v].push_back(u);
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

// Function to perform depth-first search (DFS) traversal
// adj: a 2D vector of integers representing the adjacency list
// n: an integer representing the number of vertices in the graph
// start: an integer representing the starting vertex for DFS
void dfs(vector<int> adj[], int n, int start, vector<bool> &visited)
{
    // mark the starting vertex as visited
    visited[start] = true;
    // print the starting vertex
    cout << start << " ";
    // iterate through the neighbours of the starting vertex
    for (auto node : adj[start])
    {
        if (visited[node] == false)
        {
            // call dfs for unvisited neighbours of the start node
            dfs(adj, n, node, visited);
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of vertices : " << endl;
    cin >> n;

    // Initialize the adjacency list
    vector<int> adj[n + 1];

    int m;
    cout << "Enter the number of edges : " << endl;
    cin >> m;

    // Initialize the graph
    init_graph(adj, m);
    cout << "adjacency list given by : " << endl;
    display(adj, n + 1);

    int start;
    cout << "enter the start node for dfs : " << endl;
    cin >> start;

    cout << "the depth first search traversal with start node : " << start << " given by : " << endl;
    vector<bool> visited(n + 1, false);
    dfs(adj, n + 1, start, visited);
    return 0;
}