#include <vector>
#include <utility>
using namespace std;


class UnionFind {
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
        if (get_size(i) < get_size(j)) {
            swap(i, j);
        }
        _parent[i] += _parent[j];
        _parent[j] = i;
        return true;
    }
};