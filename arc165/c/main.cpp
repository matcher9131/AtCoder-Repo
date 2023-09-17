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
    int _group_count;

public:
    UnionFind(int n) : _parent(n, -1), _group_count(n) {}

    int get_root(int i) {
        return _parent[i] < 0 ? i : (_parent[i] = get_root(_parent[i]));
    }

    int get_size(int i) {
        return -_parent[get_root(i)];
    }

    int get_group_count() {
        return _group_count;
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
        // 連結成分の数の更新
        --_group_count;
        return true;
    }
};

int n, m;
vector<int> a, b, w;

bool isOK(int x) {
    UnionFind uf(n);
    for (int i = 0; i < m; ++i) {
        if (w[i] >= x) {
            uf.connect(a[i], b[i]);
        }
    }
    return uf.get_group_count() <= 2;
}

int binary_search() {
    int ng = 1e9 + 1;
    int ok = 0;

    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    
    return ok;
}

int main() {
    cin >> n >> m;
    a = vector<int>(m);
    b = vector<int>(m);
    w = vector<int>(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> w[i];
        --a[i];
        --b[i];
    }

    cout << binary_search() << endl;

    return 0;
}