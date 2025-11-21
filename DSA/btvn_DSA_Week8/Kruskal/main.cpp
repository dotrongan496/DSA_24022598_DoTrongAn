#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

// Tìm gốc (root) của đỉnh u trong DSU
int find_root(int u, vector<int> &parent) {
    if (parent[u] < 0) return u;
    return parent[u] = find_root(parent[u], parent);
}

// Hợp nhất hai cây có gốc r1 và r2
void union_trees(int r1, int r2, vector<int> &parent) {
    int size1 = -parent[r1];
    int size2 = -parent[r2];

    // Union by size: cây lớn hơn làm gốc
    if (size1 < size2) swap(r1, r2);

    parent[r1] += parent[r2];   // tăng kích thước cây r1
    parent[r2] = r1;            // gán r2 về con của r1
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (auto &e : edges)
        cin >> e.u >> e.v >> e.w;

    // Sắp xếp cạnh theo trọng số tăng dần
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b) {
        return a.w < b.w;
    });

    vector<int> parent(n + 1, -1);   // DSU khởi tạo
    vector<Edge> mst;                // Lưu các cạnh của MST
    int mst_weight = 0;

    for (auto &e : edges) {
        int r1 = find_root(e.u, parent);
        int r2 = find_root(e.v, parent);

        if (r1 != r2) {
            union_trees(r1, r2, parent);
            mst.push_back(e);
            mst_weight += e.w;
            if (mst.size() == n - 1) break;
        }
    }

    if (mst.size() != n - 1) {
        cout << "Unconnected Graph";
    } else {
        cout << mst_weight << "\n";
        for (auto &e : mst)
            cout << e.u << " " << e.v << " " << e.w << "\n";
    }

    return 0;
}
