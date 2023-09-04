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

class BipartiteMatching {
    int _an, _bn;
    vector<vector<int>> _edge;
    bool _dfs(int ai, unordered_set<int> &visited, vector<int> &matched) {
        for (const int bi : _edge[ai]) {
            if (visited.contains(bi)) continue;
            visited.insert(bi);
            if (matched[bi] == -1 || _dfs(matched[bi], visited, matched)) {
                matched[bi] = ai;
                return true;
            }
        }
        return false;
    }

public:
    BipartiteMatching(int an, int bn) : _an(an), _bn(bn), _edge(_an, vector<int>()) {}
    void add_edge(int ai, int bi) {
        _edge[ai].push_back(bi);
    }
    int solve() {
        vector<int> matched(_bn, -1);
        int ans = 0;
        for (int i = 0; i < _an; ++i) {
            unordered_set<int> visited;
            visited.reserve(_bn);
            ans += (int)_dfs(i, visited, matched);
        }
        return ans;
    } 
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n), d(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i] >> d[i];
    }
    
    BipartiteMatching bm(n, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i] < c[j] && b[i] < d[j]) bm.add_edge(i, j);
        }
    }

    cout << bm.solve() << endl;

    return 0;
}