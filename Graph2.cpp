#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited)
{
    visited[node] = true;

    for (int neighbor = 0; neighbor < (int)graph.size(); neighbor++)
    {
        if (graph[node][neighbor] == 1 && !visited[neighbor])
        {
            dfs(graph, neighbor, visited);
        }
    }
}

bool isConnected(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<bool> visited(n, false);

    dfs(graph, 0, visited);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }

    return true;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}
    };

    if (isConnected(graph))
        cout << "The graph is connected";
    else
        cout << "The graph is not connected";

    return 0;
}