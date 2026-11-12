
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int V = 7;
vector<int> adj[V];

// Task I: Adjacency List
void printList() {
    cout << "Task I: Adjacency List\n";

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";

        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Task I: Adjacency Matrix
void printMatrix() {
    int matrix[V][V] = {0};

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            int v = adj[i][j];
            matrix[i][v] = 1;
        }
    }

    cout << "Adjacency Matrix:\n";

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Task II: BFS
void BFS(int start) {
    bool visited[V] = {false};
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "Task II: BFS: ";

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl << endl;
}

// Task III: DFS
void DFS(int u, bool visited[]) {
    visited[u] = true;
    cout << u << " ";

    for (int i = adj[u].size() - 1; i >= 0; i--) {
        int v = adj[u][i];

        if (!visited[v]) {
            DFS(v, visited);
        }
    }
}

void runDFS(int start) {
    bool visited[V] = {false};

    cout << "Task III: DFS: ";
    DFS(start, visited);
    cout << endl << endl;
}

// Task IV: Shortest Path
void shortestPath(int start, int end) {
    bool visited[V] = {false};
    int parent[V];

    for (int i = 0; i < V; i++) {
        parent[i] = -1;
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (u == end) {
            break;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[end]) {
        cout << "No path exists.\n";
        return;
    }

    vector<int> path;

    for (int v = end; v != -1; v = parent[v]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());

    cout << "Task IV: Shortest Path: ";

    for (int v : path) {
        cout << v << " ";
    }

    cout << "\nTotal Hop Count: " << path.size() - 1 << endl;
}

int main() {
    // Undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4, 5};
    adj[3] = {1};
    adj[4] = {1, 2, 6};
    adj[5] = {2, 6};
    adj[6] = {4, 5};

    printList();
    printMatrix();
    BFS(0);
    runDFS(4);
    shortestPath(1, 2);

    return 0;
}
