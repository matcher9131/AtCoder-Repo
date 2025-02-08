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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }

    UnionFind uf(n);
    vector<int> extraEdges;
    for (int i = 0; i < m; ++i) {
        bool result = uf.connect(a[i], b[i]);
        if (!result) {
            extraEdges.push_back(i);
        }
    }

    vector<int> roots;
    for (int i = 0; i < n; ++i) {
        if (uf.get_root(i) == i) {
            roots.push_back(i);
        }
    }

    if (roots.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<bool> done(roots.size());
    int next = 1;
    cout << roots.size() - 1 << endl;
    for (int i = 0; i < roots.size() - 1; ++i) {
        int edgeIndex = extraEdges[i];
        int from = a[edgeIndex];
        int fromRoot = uf.get_root(from);
        int fromRootIndex = lower_bound(roots.begin(), roots.end(), fromRoot) - roots.begin();
        if (!done[fromRootIndex]) {
            int to = roots[fromRootIndex == 0 ? 1 : 0];
            cout << edgeIndex + 1 << " " << from + 1 << " " << to + 1 << endl;
            done[fromRootIndex] = true;
            done[fromRootIndex == 0 ? 1 : 0] = true;
        } else {
            int to = roots[next];
            cout << edgeIndex + 1 << " " << from + 1 << " " << to + 1 << endl;
            done[next] = true;
        }
        while (next < done.size() && done[next]) ++next;
    }

    return 0;
}