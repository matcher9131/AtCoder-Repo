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

#include <atcoder/modint>
using mint = atcoder::modint998244353;

class UnionFind {
public:
    // 頂点iが親ならparent[i] == -1 * 連結成分の頂点数
    vector<int> _parent;
    
    UnionFind(int n) {
        _parent = vector<int>(n, -1);
    }

    int getRoot(int i) {
        return _parent[i] < 0 ? i : (_parent[i] = getRoot(_parent[i]));
    }

    int getSize(int i) {
        return -_parent[getRoot(i)];
    }

    bool connect(int i, int l, int r) {
        l = getRoot(l);
        r = getRoot(r);
        // サイズの更新
        _parent[i] = _parent[l] + _parent[r];
        // 親の更新
        _parent[l] = i;
        _parent[r] = i;
        return true;
    }
};

int n;
vector<vector<pair<int, mint>>> g;

void dfs(int root, vector<mint> &prob) {
    for (const auto& [nv, p] : g[root]) {
        prob[nv] = prob[root] + p;
        dfs(nv, prob);
    }
}

int main() {
    cin >> n;
    vector<int> p(n - 1), q(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> p[i] >> q[i];
        --p[i]; --q[i];
    }

    g = vector<vector<pair<int, mint>>>(2 * n - 1, vector<pair<int, mint>>());
    UnionFind uf(2 * n - 1);
    for (int i = 0; i < n - 1; ++i) {
        mint a = uf.getSize(p[i]);
        mint b = uf.getSize(q[i]);
        int l = uf.getRoot(p[i]);
        int r = uf.getRoot(q[i]);
        uf.connect(n + i, l, r);
        g[n + i].emplace_back(l, a / (a + b));
        g[n + i].emplace_back(r, b / (a + b));
    }

    vector<mint> prob(2 * n - 1, 0);
    dfs(2 * n - 2, prob);

    cout << prob[0].val();
    for (int i = 1; i < n; ++i) {
        cout << " " << prob[i].val();
    }
    cout << endl;

    return 0;
}