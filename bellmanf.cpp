#include <iostream>
#include <vector>

using namespace std;

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] + w < dist[v]) {
                dist[v] = w + dist[u];
            }
        }
    }

    return dist;
}

int main() {
    // Example usage
    int n = 5; // Number of vertices
    int m = 7; // Number of edges

    // Edges in the format {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 3, 2},
        {2, 3, -3},
        {2, 4, 1},
        {3, 4, 5},
        {4, 2, 2},
        {5, 4, 3}
    };

    int src = 1; // Source vertex

    vector<int> result = bellmonFord(n, m, src, edges);

    // Displaying the results
    cout << "Shortest distances from source vertex " << src << " are:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << "Vertex " << i << ": " << result[i] << endl;
    }

    return 0;
}
