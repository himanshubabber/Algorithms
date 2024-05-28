#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    if (src < 1 || src > n || dest < 1 || dest > n) {
        return -1;
    }
    vector<vector<int>> mat(n, vector<int>(n, 1e9));

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0] - 1;
        int v = edges[i][1] - 1;
        int w = edges[i][2];
        mat[u][v] = w;
    }
    for (int i = 0; i < n; i++) mat[i][i] = 0;
    for (int via = 0; via < n; via++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][via] != 1e9 && mat[via][j] != 1e9)
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
            }
        }
    }

    return mat[src - 1][dest - 1];
}

int main() {
    // Example usage
    int n = 4;
    int m = 6;
    int src = 1;
    int dest = 4;

    // Edge list: {from, to, weight}
    vector<vector<int>> edges = {{1, 2, 1}, {2, 3, 2}, {3, 4, 3}, {4, 1, -1}, {2, 4, 1}, {1, 3, 5}};

    int result = floydWarshall(n, m, src, dest, edges);

   if (result == -1) {
        cout << "Invalid source or destination vertex." << endl;
    } else {
        cout << "Shortest path from " << src << " to " << dest << ": " << result << endl;
    }

    return 0;
}
