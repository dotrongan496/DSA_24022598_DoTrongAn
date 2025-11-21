#include <bits/stdc++.h>
#include <PriorityQueue.h>
using namespace std;


void prim(int n, vector<vector<pair<int,int>>> &adj, int start = 0) {
    vector<int> key(n, INF);         // trọng số nhỏ nhất để kết nối đỉnh
    vector<int> parent(n, -1);       // lưu cây MST
    vector<bool> inMST(n, false);    // đánh dấu đỉnh đã chọn

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    // Bắt đầu từ "start"
    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;
        inMST[u] = true;

        // Duyệt các cạnh kề của u
        for (auto &x : adj[u]) {
            int v = x.second;
            int w = x.first;

            // nếu tìm được cạnh tốt hơn
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // In MST
    cout << "Edges in MST:\n";
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << "   weight = " << key[i] << "\n";
            total += key[i];
        }
    }
    cout << "Total weight = " << total << "\n";
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    prim(n, adj, 0);
/*
4 5
0 1 2
0 2 3
1 2 1
1 3 4
2 3 5
*/

}
