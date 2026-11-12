#include <iostream>
#include <vector>
using namespace std;

void dfsComponent(vector<vector<int>>& graph, int node,
                  vector<bool>& visited, vector<int>& component)
{
    visited[node] = true;

    component.push_back(node);

    for (int neighbor = 0; neighbor < (int)graph.size(); neighbor++)
    {
        if (graph[node][neighbor] == 1 && !visited[neighbor])
        {
            dfsComponent(graph, neighbor, visited, component);
        }
    }
}

vector<vector<int>> connectedComponents(vector<vector<int>>& graph)
{
    int n = graph.size();

    vector<bool> visited(n, false);

    vector<vector<int>> components;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> component;

            dfsComponent(graph, i, visited, component);

            components.push_back(component);
        }
    }

    return components;
}

int main()
{
    vector<vector<int>> graph = {
        {0, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0}
    };

    vector<vector<int>> components = connectedComponents(graph);

    cout << "Connected Components:" << endl;

    for (int i = 0; i < (int)components.size(); i++)
    {
        cout << "Component " << i + 1 << ": ";

        for (int j = 0; j < (int)components[i].size(); j++)
        {
            cout << components[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}