#include <bits/stdc++.h>
using namespace std;

vector<int> kahnTopologicalSort(int n, vector<vector<int>>& adj) {
    vector<int> inDegree(n, 0);

    // Step 1: compute in-degree of each node
    for (int u = 0; u < n; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: push all nodes with in-degree 0 into queue
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: process nodes
    vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        // Decrease in-degree of neighbors
        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // Step 4: check if topological order exists
    if ((int)topoOrder.size() != n) {
        cout << "Cycle detected! No topological sort possible.\n";
        return {};
    }

    return topoOrder;
}

int main() {
    int n = 6;  // number of nodes
    vector<vector<int>> adj(n);

    // Graph edges (example: same as dry run before)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = kahnTopologicalSort(n, adj);

    if (!topo.empty()) {
        cout << "Topological Order: ";
        for (int x : topo) cout << x << " ";
        cout << endl;
    }
    return 0;
}


// DFS

#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited, st);
        }
    }
    st.push(u); // push after visiting all neighbors
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    vector<int> topoOrder;
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }
    return topoOrder;
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    // Graph edges (same example as before)
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSortDFS(n, adj);

    cout << "Topological Order: ";
    for (int x : topo) cout << x << " ";
    cout << endl;

    return 0;
}

