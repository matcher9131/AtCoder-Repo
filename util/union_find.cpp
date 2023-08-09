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