#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

int parent[100];

int find(int i)
{
    if (parent[i] == i)
        return i;

    return parent[i] = find(parent[i]);
}

void unionSet(int u, int v)
{
    parent[find(u)] = find(v);
}

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

void kruskalMST(Edge edges[], int V, int E)
{
    sort(edges, edges + E, compare);

    for (int i = 0; i < V; i++)
        parent[i] = i;

    cout << "\nKruskal's MST:\n";
    cout << "Edge\tWeight\n";

    int count = 0;
    int total = 0;

    for (int i = 0; i < E && count < V - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        if (find(u) != find(v))
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            total += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    cout << "Total weight = " << total << endl;
}

int main()
{
    const int V = 5;
    const int E = 7;

    Edge edges[E] = {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    kruskalMST(edges, V, E);

    return 0;
}