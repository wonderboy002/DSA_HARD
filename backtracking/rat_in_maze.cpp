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
void printPaths(vector<vector<int>> &maze, int x, int y, vector<vector<bool>> &visited, int N, string &output)
{
    // base case
    if (x == N - 1 && y == N - 1)
    {
        cout << output << endl;

        return;
    }

    // recursion ka khel
    // UP path

    if (isSafe(x - 1, y, maze, visited))
    {
        visited[x - 1][y] = true;
        output.push_back('U');
        printPaths(maze, x - 1, y, visited, N, output);
        visited[x - 1][y] = false;
        output.pop_back();
    }

    // right path
    if (isSafe(x, y + 1, maze, visited))
    {
        visited[x][y + 1] = true;
        output.push_back('R');
        printPaths(maze, x, y + 1, visited, N, output);
        visited[x][y + 1] = false;
        output.pop_back();
    }

    // down path
    if (isSafe(x + 1, y, maze, visited))
    {
        visited[x + 1][y] = true;
        output.push_back('D');
        printPaths(maze, x + 1, y, visited, N, output);
        visited[x + 1][y] = false;
        output.pop_back();
    }

    // left path
    if (isSafe(x, y - 1, maze, visited))
    {
        visited[x][y - 1] = true;
        output.push_back('L');
        printPaths(maze, x, y - 1, visited, N, output);
        visited[x][y - 1] = false;
        output.pop_back();
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
    printPaths(maze, 0, 0, visited, 4, output);

    return 0;
}