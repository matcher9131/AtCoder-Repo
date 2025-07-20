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
#include <functional>
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    UnionFind uf(n);
    vector<ll> ans(m);
    ans.back() = (ll)n * (n - 1) / 2;
    for (int i = m - 1; i > 0; --i) {
        if (uf.get_root(a[i]) != uf.get_root(b[i])) {
            ans[i - 1] = ans[i] - (ll)uf.get_size(a[i]) * (ll)uf.get_size(b[i]);
        } else {
            ans[i - 1] = ans[i];
        }
        uf.connect(a[i], b[i]);
    }

    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }

    return 0;
}