#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

class UnionFind {
    vector<int> _parent;
    vector<vector<int>> _top;
    int _k;

public:
    UnionFind(int n, int k) : _parent(n, -1), _top(n), _k(k) {
        for (ll i = 0; i < n; ++i) {
            _top[i].push_back(i);
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
        for (const int v : _top[j]) {
            _top[i].push_back(v);
        }
        _top[j].clear();
        sort(_top[i].begin(), _top[i].end(), greater<>());
        if ((ll)_top[i].size() > _k) _top[i].resize(_k);
        return true;
    }

    int get_kth_largest(int i, int k) {
        i = get_root(i);
        return k >= (ll)_top[i].size() ? -1 : _top[i][k];
    }
};

int main() {
    ll n, nq;
    cin >> n >> nq;
    UnionFind uf(n, 10);

    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll u, v;
            cin >> u >> v;
            --u;
            --v;
            uf.connect(u, v);
        } else {
            ll v, k;
            cin >> v >> k;
            --v;
            --k;
            ll ans = uf.get_kth_largest(v, k);
            cout << (ans == -1 ? -1 : ans+1) << endl;
        }
    }

    return 0;
}