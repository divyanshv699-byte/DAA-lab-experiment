#include <iostream>
#include <vector>
using namespace std;

void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited,
         vector<int>& component) {
    
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited, component);
        }
    }
}

int main() {
    int vertices = 7;

    vector<vector<int>> adj(vertices);

    adj[0] = {1, 2};
    adj[1] = {0, 2};
    adj[2] = {0, 1};

    adj[3] = {4};
    adj[4] = {3};

    adj[5] = {6};
    adj[6] = {5};

    vector<bool> visited(vertices, false);

    int componentCount = 0;

    cout << "Connected Components:\n";

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            componentCount++;

            vector<int> component;
            DFS(i, adj, visited, component);

            cout << "Component " << componentCount << ": ";

            for (int node : component) {
                cout << node << " ";
            }

            cout << endl;
        }
    }

    cout << "\nTotal Connected Components: "
         << componentCount << endl;

    return 0;
}