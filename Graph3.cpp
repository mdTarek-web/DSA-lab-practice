#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& graph, int start)
{
    int n = graph.size();

    vector<int> dist(n, -1);

    queue<int> q;

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int neighbor = 0; neighbor < n; neighbor++)
        {
            if (graph[node][neighbor] == 1 && dist[neighbor] == -1)
            {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 1},
        {0, 1, 1, 0}
    };

    int start = 0;

    vector<int> result = shortestPath(graph, start);

    cout << "Shortest path from " << start << ": [";

    for (int i = 0; i < (int)result.size(); i++)
    {
        cout << result[i];

        if (i != (int)result.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]";

    return 0;
}