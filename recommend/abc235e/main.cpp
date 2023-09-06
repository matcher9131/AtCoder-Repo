#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <climits>
#include <cfloat>
#include <utility>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <numeric>
using namespace std;
using ll = long long;

class UnionFind {
    // 頂点iが親ならparent[i] == -1 * 連結成分の頂点数
    vector<int> _parent;

public:
    UnionFind(int n) : _parent(n, -1) {}

    int get_root(int i) {
        return _parent[i] < 0 ? i : (_parent[i] = get_root(_parent[i]));
    }

    int get_size(int i) {
        return -_parent[get_root(i)];
    }

    bool connect(int i, int j) {
        i = get_root(i);
        j = get_root(j);
        if (i == j) return false;
        // 大きいほうに小さいほうをくっつける
        if (get_size(i) < get_size(j)) {
            swap(i, j);
        }
        // サイズの更新
        _parent[i] += _parent[j];
        // 親の更新
        _parent[j] = i;
        return true;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    priority_queue<tuple<ll, int, int, int>, vector<tuple<ll, int, int, int>>, greater<tuple<ll, int, int, int>>> edge;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a;
        --b;
        edge.emplace(c, a, b, -1);
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        edge.emplace(w, u, v, i);
    }
    vector<bool> ans(q);

    UnionFind uf(n);
    while (!edge.empty()) {
        auto [cost, v1, v2, i] = edge.top();
        edge.pop();
        if (i >= 0) {
            ans[i] = uf.get_root(v1) != uf.get_root(v2);
        } else {
            if (uf.get_root(v1) != uf.get_root(v2)) uf.connect(v1, v2);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << (ans[i] ? "Yes" : "No") << endl;
    }

    return 0;
}