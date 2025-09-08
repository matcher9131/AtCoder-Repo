#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


class UnionFind {
    vector<int> _parent;
    vector<unordered_set<int>> _black;

public:
    UnionFind(int n) : _parent(n, -1), _black(n) {}

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
        for (const int v : _black[j]) {
            _black[i].insert(v);
        }
        _black[j].clear();
        return true;
    }

    void turn_color(int i) {
        int root = get_root(i);
        if (_black[root].contains(i)) _black[root].erase(i);
        else _black[root].insert(i);
    }

    bool has_black(int i) {
        int root = get_root(i);
        return !_black[root].empty();
    }
};

int main() {
    ll n, nq;
    cin >> n >> nq;
    UnionFind uf(n);

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            uf.connect(u, v);
        } else if (type == 2) {
            ll v;
            cin >> v;
            --v;
            uf.turn_color(v);
        } else {
            ll v;
            cin >> v;
            --v;
            cout << (uf.has_black(v) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}