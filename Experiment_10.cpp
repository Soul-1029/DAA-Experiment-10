// Write a program to find the single source shortest path using the bellman ford algorithm and extend it to detect negative-weight cycles in a weighted directed graph
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(vector<Edge>& edges, int vertices, int source) {
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= vertices - 1; i++) {
        for (auto edge : edges) {
            if (dist[edge.u] != INT_MAX &&
                dist[edge.u] + edge.weight < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.weight;
            }
        }
    }

    for (auto edge : edges) {
        if (dist[edge.u] != INT_MAX &&
            dist[edge.u] + edge.weight < dist[edge.v]) {
            cout << "\nNegative-weight cycle detected.\n";
            return;
        }
    }

    cout << "\nShortest distances from source " << source + 1 << ":\n";

    for (int i = 0; i < vertices; i++) {
        cout << "Vertex " << i + 1 << " : ";

        if (dist[i] == INT_MAX)
            cout << "INF";
        else
            cout << dist[i];

        cout << endl;
    }
}

int main() {
    int vertices, edgesCount;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edgesCount;

    vector<Edge> edges(edgesCount);

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--;
        edges[i].v--;
    }

    int source;

    cout << "Enter source vertex: ";
    cin >> source;
    source--;

    bellmanFord(edges, vertices, source);

    return 0;
}
//Name- Hari krishna k
// Branch - CSDA
//Roll no. - 25/DA/028