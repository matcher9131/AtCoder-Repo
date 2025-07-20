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
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;

class UnionFind {
    // 頂点iが親ならparent[i] == -1 * 連結成分の頂点数
    vector<int> _parent;
    // 頂点iが親の連結成分でループを持つかどうか
    vector<bool> _has_loop;

public:
    UnionFind(int n) : _parent(n, -1), _has_loop(n) {}

    int get_root(int i) {
        return _parent[i] < 0 ? i : (_parent[i] = get_root(_parent[i]));
    }

    int get_size(int i) {
        return -_parent[get_root(i)];
    }

    bool is_root(int i) {
        return _parent[i] < 0;
    }

    bool has_loop(int i) {
        return _has_loop[i];
    }

    bool connect(int i, int j) {
        i = get_root(i);
        j = get_root(j);
        if (i == j) {
            if (_has_loop[i]) return false;
            _has_loop[i] = true;
            return true;
        }
        if (_has_loop[i] && _has_loop[j]) return false;
        // 大きいほうに小さいほうをくっつける
        if (get_size(i) < get_size(j)) {
            swap(i, j);
        }
        // サイズの更新
        _parent[i] += _parent[j];
        // 親の更新
        _parent[j] = i;
        if (_has_loop[j]) {
            _has_loop[j] = false;
            _has_loop[i] = true;
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        if (!uf.connect(u, v)) {
            cout << 0 << endl;
            return 0;
        }
    }

    mint ans = 1;
    for (int i = 0; i < n; ++i) {
        if (uf.is_root(i)) {
            if (!uf.has_loop(i)) {
                cout << 0 << endl;
                return 0;
            }
            ans *= 2;
        }
    }

    cout << ans.val() << endl;

    return 0;
}