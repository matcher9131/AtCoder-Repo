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

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> g(h, vector<bool>(w));
    UnionFind uf(h * w);
    for (int qi = 0; qi < q; ++qi) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, j;
            cin >> i >> j;
            --i;
            --j;
            g[i][j] = true;
            for (int dir = 0; dir < 4; ++dir) {
                int ni = i + dy[dir];
                int nj = j + dx[dir];
                if (ni >= 0 && ni < h && nj >= 0 && nj < w && g[ni][nj]) {
                    uf.connect(i * w + j, ni * w + nj);
                }
            }
        } else {
            int si, sj, gi, gj;
            cin >> si >> sj >> gi >> gj;
            --si;
            --sj;
            --gi;
            --gj;
            if (g[si][sj] && g[gi][gj] && uf.get_root(si * w + sj) == uf.get_root(gi * w + gj)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}