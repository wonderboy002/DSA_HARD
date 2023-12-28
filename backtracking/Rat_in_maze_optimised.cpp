#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    if (x >= 0 && y >= 0 && x < maze.size() && y < maze.size() && visited[x][y] == false && maze[x][y] == 1)
    {
        return true;
    }
    return false;
}
void printPaths(vector<vector<int>> &maze, int x, int y, vector<vector<bool>> &visited, int N, string &output, vector<int> &dx, vector<int> &dy)
{
    // base case
    if (x == N - 1 && y == N - 1)
    {
        cout << output << endl;

        return;
    }

    // recursion ka khel
    string directions = "DLRU";
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(x + dx[i], y + dy[i], maze, visited))
        {
            visited[x + dx[i]][y + dy[i]] = true;
            output.push_back(directions[i]);
            printPaths(maze, x + dx[i], y + dy[i], visited, N, output, dx, dy);
            visited[x + dx[i]][y + dy[i]] = false;
            output.pop_back();
        }
    }
}
int main()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 1}};
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    string output = "";
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, -1, 1, 0};
    if (maze[3][3] == 1)
    {

        printPaths(maze, 0, 0, visited, 4, output, dx, dy);
    }

    return 0;
}