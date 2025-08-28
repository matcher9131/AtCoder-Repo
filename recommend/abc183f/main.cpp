#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


class UnionFind {
    vector<int> _parent;
    vector<unordered_map<int, int>> _count;

public:
    UnionFind(int n, vector<int> &color) : _parent(n, -1), _count(n) {
        for (int i = 0; i < n; ++i) {
            _count[i][color[i]] = 1;
        }
    }

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
        if (get_size(i) < get_size(j)) {
            swap(i, j);
        }
        _parent[i] += _parent[j];
        _parent[j] = i;
        for (const auto& [key, val] : _count[j]) {
            _count[i][key] += val;
        }
        return true;
    }

    int get_count(int i, int color) {
        return _count[get_root(i)][color];
    }
};

int main() {
    int n, nq;
    cin >> n >> nq;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }

    UnionFind uf(n, c);
    while (nq--) {
        ll type, x, y;
        cin >> type >> x >> y;
        --x;
        --y;
        if (type == 1) {
            uf.connect(x, y);
        } else {
            cout << uf.get_count(x, y) << endl;
        }
    }

    return 0;
}