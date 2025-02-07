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


int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> depth(n, -1);
    vector<int> parent(n, -1);
    function<void(int, int, int)> dfs = [&](int v, int currentDepth, int currentParent) -> void {
        depth[v] = currentDepth;
        parent[v] = currentParent;
        for (const int nv : g[v]) {
            if (depth[nv] >= 0) continue;
            dfs(nv, currentDepth + 1, v);
        }
    };
    dfs(0, 0, -1);
    
    unordered_set<int> v;
    // depth, parent, index
    priority_queue<tuple<int, int, int>> que;
    for (int i = 0; i < k; ++i) {
        int vi;
        cin >> vi;
        --vi;
        que.emplace(depth[vi], parent[vi], vi);
        v.insert(vi);
    }

    while (!que.empty()) {
        auto [d, p, i] = que.top();
        que.pop();
        if (que.empty()) break;
        if (!v.contains(p)) {
            v.insert(p);
            que.emplace(depth[p], parent[p], p);
        }
    }

    cout << v.size() << endl;

    return 0;
}