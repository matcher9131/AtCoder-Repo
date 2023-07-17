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
using namespace std;
using ll = long long;

int n, m;

class UnionFind {
public:
    // 頂点iが親ならparent[i] == -1 * 連結成分の頂点数
    vector<int> parent;
    
    UnionFind() {
        parent = vector<int>(n + m, -1);
    }

    int getRoot(int i) {
        return this->parent[i] < 0 ? i : (parent[i] = getRoot(parent[i]));
    }

    int getSize(int i) {
        return -this->parent[this->getRoot(i)];
    }

    // 返り値は新たに発電所につながった都市の数
    int connect(int i, int j) {
        i = this->getRoot(i);
        j = this->getRoot(j);
        if (i == j) return 0;
        if ((i < n) ^ (j < n)) { // 片方の親のみ発電所 
            if (j >= n) swap(i, j);
            int tmp = -this->parent[j];
            // サイズの更新
            this->parent[i] += this->parent[j];
            // 親の更新
            this->parent[j] = i;
            return tmp;
        }  else { // 双方の親が発電所
            if (this->getSize(i) < this->getSize(j)) swap(i, j);
            // サイズの更新
            this->parent[i] += this->parent[j];
            // 親の更新
            this->parent[j] = i;
            return 0;
        }
    }
};

int main() {
    int e;
    cin >> n >> m >> e;
    vector<pair<int, int>> edges(e);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        edges[i] = make_pair(u, v);
    }
    // 電線iが最後まで生きているかどうか
    vector<bool> alive(e, true);

    int q;
    cin >> q;
    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        int xi;
        cin >> xi;
        --xi;
        x[i] = xi;
        alive[xi] = false;
    }

    // 最後まで生きている電線を繋ぐ
    UnionFind uf;
    int count = 0;
    for (int i = 0; i < e; ++i) {
        if (alive[i]) {
            count += uf.connect(edges[i].first, edges[i].second);
        }
    }

    // イベントを逆順にして電線を1つずつ付けながら解を得る
    vector<int> answers(q);
    for (int qi = q - 1; qi >= 0; --qi) {
        answers[qi] = count;
        count += uf.connect(edges[x[qi]].first, edges[x[qi]].second);
    }

    for (const int ans : answers) {
        cout << ans << endl;
    }

    return 0;
}