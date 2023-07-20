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
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;
using ll = long long;

#include <vector>
#include <utility>
using namespace std;

class UnionFind {
public:
    // 頂点iが親ならparent[i] == -1 * 連結成分の頂点数
    vector<int> parent;
    
    UnionFind(int n) {
        parent = vector<int>(n, -1);
    }

    int getRoot(int i) {
        return this->parent[i] < 0 ? i : (parent[i] = getRoot(parent[i]));
    }

    int getSize(int i) {
        return -this->parent[this->getRoot(i)];
    }

    bool connect(int i, int j) {
        i = this->getRoot(i);
        j = this->getRoot(j);
        if (i == j) return false;
        // 大きいほうに小さいほうをくっつける
        if (this->getSize(i) < this->getSize(j)) {
            swap(i, j);
        }
        // サイズの更新
        this->parent[i] += this->parent[j];
        // 親の更新
        this->parent[j] = i;
        return true;
    }
};

int n;
vector<bool> pre;
int pos = -1;
stack<int> history;

void dfsInner(const vector<int> &x, int from) {
    pre[from] = true;
    history.push(from);
    int to = x[from];
    if (pre[to]) {
        pos = to;
        return;
    }
    dfsInner(x, to);
    if (pos != -1) return;
    history.pop();
}

void dfs(const vector<int> &x, int from) {
    pos = -1;
    fill(pre.begin(), pre.end(), false);
    history = stack<int>();
    dfsInner(x, from);
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n);
    vector<ll> c(n);
    UnionFind uf(n);
    pre = vector<bool>(n);
    for (int i = 0; i < n; ++i) {
        int xi;
        cin >> xi;
        --xi;
        x[i] = xi;
        uf.connect(i, xi);
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll answer = 0;
    for (int i = 0; i < n; ++i) {
        // 全ての親に対してdfs
        if (uf.parent[i] < 0) {
            dfs(x, i);
            if (pos == -1) continue;
            // サイクル復元のついでに最小辺を記録
            ll min = 1e15;
            while (!history.empty()) {
                int from = history.top();
                history.pop();
                min = std::min(min, c[from]);
                if (from == pos) break;
            }
            answer += min;
        }
    }

    cout << answer << endl;

    return 0;
}