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
    int n;
    string s, t;
    cin >> n >> s >> t;

    UnionFind uf(26);
    vector<int> charMap(26, -1);
    vector<bool> isInCycle(26);
    for (int i = 0; i < n; ++i) {
        int from = s[i] - 'a';
        int to = t[i] - 'a';
        if (charMap[from] == -1) {
            charMap[from] = to;
            bool result = uf.connect(from, to);
            if (!result) {
                isInCycle[uf.get_root(from)] = true;
            }
        } else if (charMap[from] != to) {
            cout << -1 << endl;
            return 0;
        }
    }

    int numUnused = count(charMap.begin(), charMap.end(), -1);
    set<int> cycleRoot;
    for (int i = 0; i < 26; ++i) {
        if (isInCycle[i]) {
            cycleRoot.emplace(uf.get_root(i));
        }
    }
    if (numUnused == 0 && accumulate(cycleRoot.begin(), cycleRoot.end(), 0, [&](int acc, int root) { return acc + uf.get_size(root); }) == 26) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        if (cycleRoot.contains(i)) {
            int size = uf.get_size(i);
            if (size > 1) {
                ans += uf.get_size(i) + 1;
            }
        } else if (charMap[i] != -1 && uf.get_root(i) == i) {
            ans += uf.get_size(i) - 1;
        }
    }
    
    cout << ans << endl;
    return 0;
}