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
using Graph = vector<vector<int>>;

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

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        // 後で辺に対して全捜査するので片方向でも問題ない
        edges[i] = make_pair(a, b);
    }
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    UnionFind uf(n);
    for (const auto& edge : edges) {
        // 異色頂点間の辺のみを張る
        if (c[edge.first] != c[edge.second]) {
            uf.connect(edge.first, edge.second);
        }
    }
    
    for (const auto& edge : edges) {
        // 同色頂点間の辺のみを見て、同じグループにいれば"Yes"
        if (c[edge.first] == c[edge.second] && uf.getRoot(edge.first) == uf.getRoot(edge.second)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}