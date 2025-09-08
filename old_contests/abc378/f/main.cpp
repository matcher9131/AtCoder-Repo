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
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    ll ans = 0;
    vector<bool> visited(n);
    function<void(int, vector<int>&)> dfs = [&](int cv, vector<int>& v3d) {
        visited[cv] = true;
        for (const int nv : g[cv]) {
            if (!visited[nv] && g[nv].size() == 3) {
                v3d.push_back(nv);
                dfs(nv, v3d);
            }
        }
    };
    for (int v = 0; v < n; ++v) {
        if (visited[v] || g[v].size() != 3) continue;

        vector<int> v3d;
        v3d.push_back(v);
        dfs(v, v3d);

        set<int> v2d;
        for (int i = 0; i < v3d.size(); ++i) {
            int cv = v3d[i];
            for (const int nv : g[cv]) {
                if (g[nv].size() == 2) {
                    v2d.insert(nv);
                }
            }
        }
        int nv2d = v2d.size();

        ans += (ll)nv2d * (nv2d - 1LL) / 2LL;
    }

    cout << ans << endl;

    return 0;
}