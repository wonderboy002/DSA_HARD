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

// Function to perform breadth-first search (BFS) traversal
// adj: a 2D vector of integers representing the adjacency list
// n: an integer representing the number of vertices in the graph
// start: an integer representing the starting vertex for BFS
void bfs(vector<int> adj[], int n, int start)
{
    // Initialize a vector of booleans to keep track of visited vertices
    vector<bool> visited(n + 1, false);
    // Initialize a queue to perform BFS
    queue<int> q;
    // Add the starting vertex to the queue and mark it as visited
    q.push(start);
    visited[start] = true;

    // Continue BFS until the queue is empty
    while (!q.empty())
    {
        // Get the current vertex from the queue
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Iterate through the neighbors of the current vertex
        for (auto n : adj[node])
        {
            // If the neighbor has not been visited, add it to the queue and mark it as visited
            if (visited[n] == false)
            {
                q.push(n);
                visited[n] = true;
            }
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
    cout << "enter the start node for bfs : " << endl;
    cin >> start;

    cout << "the breadth first search traversal with start node : " << start << " given by : " << endl;
    bfs(adj, n + 1, start);
    return 0;
}