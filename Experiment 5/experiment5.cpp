#include <iostream>
#include <vector>
using namespace std;

int timer = 0;

void DFS(int u, int parent, vector<vector<int>>& adj, vector<int>& disc,
         vector<int>& low, vector<bool>& ap) {
    disc[u] = low[u] = ++timer;
    int children = 0;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            children++;
            DFS(v, u, adj, disc, low, ap);

            low[u] = min(low[u], low[v]);

            if (parent == -1 && children > 1)
                ap[u] = true;

            if (parent != -1 && low[v] >= disc[u])
                ap[u] = true;
        }
        else if (v != parent) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> disc(V, -1), low(V, -1);
    vector<bool> ap(V, false);

    for (int i = 0; i < V; i++)
        if (disc[i] == -1)
            DFS(i, -1, adj, disc, low, ap);

    cout << "Articulation Points: ";
    for (int i = 0; i < V; i++)
        if (ap[i])
            cout << i << " ";

    return 0;
}