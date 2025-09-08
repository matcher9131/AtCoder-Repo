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
    vector<int> _parent;
    vector<vector<int>> _vset;

public:
    UnionFind(int n) : _parent(n, -1), _vset(n, vector<int>(10, -1)) {
        for (int i = 0; i < n; ++i) {
            _vset[i][0] = i;
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
        for (const int v : _vset[j]) {
            if (v >= 0) {
                _vset[i].push_back(v);
            }
        }
        sort(_vset[i].begin(), _vset[i].end(), greater<int>());
        _vset[i].resize(10);
        return true;
    }

    int get_v_num(int i, int k) {
        return _vset[get_root(i)][k];
    }
};

int main() {
    int n, nq;
    cin >> n >> nq;
    UnionFind uf(n);

    for (int i = 0; i < nq; ++i) {
        int k, x, y;
        cin >> k >> x >> y;
        --x;
        --y;
        if (k == 1) {
            uf.connect(x, y);
        } else {
            int ans = uf.get_v_num(x, y);
            cout << (ans == -1 ? -1 : ans + 1) << endl;
        }
    }

    return 0;
}