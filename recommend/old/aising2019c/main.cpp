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
    // 親なら(-black_size, -white_size)、子なら(root, 0)
    vector<pair<ll, ll>> _parent;

public:
    UnionFind(vector<bool> &v) {
        _parent = vector<pair<ll, ll>>(v.size());
        for (int i = 0; i < v.size(); ++i) {
            _parent[i] = v[i] ? make_pair(-1, 0) : make_pair(0, -1);
        }
    }

    bool is_root(int i) {
        return _parent[i].first < 0 || _parent[i].second < 0;
    }

    int get_root(int i) {
        return is_root(i) ? i : (_parent[i] = make_pair(get_root(_parent[i].first), 0)).first;
    }

    ll get_black_size(int i) {
        return -_parent[get_root(i)].first;
    }

    ll get_white_size(int i) {
        return -_parent[get_root(i)].second;
    }

    bool connect(int i, int j) {
        i = get_root(i);
        j = get_root(j);
        if (i == j) return false;
        // 大きいほうに小さいほうをくっつける
        if (get_black_size(i) + get_white_size(i) < get_black_size(j) + get_white_size(j)) {
            swap(i, j);
        }
        // サイズの更新
        _parent[i].first += _parent[j].first;
        _parent[i].second += _parent[j].second;
        // 親の更新
        _parent[j] = make_pair(i, 0);
        return true;
    }
};

int main() {
    int h, w;
    cin >> h >> w;
    vector<bool> v(h * w);
    string t;
    for (int i = 0; i < h; ++i) {
        cin >> t;
        for (int j = 0; j < w; ++j) {
            v[i * w + j] = t[j] == '#';
        }
    }

    UnionFind uf(v);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (i > 0 && v[i * w + j] != v[(i - 1) * w + j]) uf.connect(i * w + j, (i - 1) * w + j);
            if (i < h - 1 && v[i * w + j] != v[(i + 1) * w + j]) uf.connect(i * w + j, (i + 1) * w + j);
            if (j > 0 && v[i * w + j] != v[i * w + j - 1]) uf.connect(i * w + j, i * w + j - 1);
            if (j < w - 1 && v[i * w + j] != v[i * w + j + 1]) uf.connect(i * w + j, i * w + j + 1);
        }
    }

    ll ans = 0;
    for (int i = 0; i < h * w; ++i) {
        if (uf.is_root(i)) {
            ans += uf.get_black_size(i) * uf.get_white_size(i);
        }
    }

    cout << ans << endl;

    return 0;
}