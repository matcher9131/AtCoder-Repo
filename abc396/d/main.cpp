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
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].emplace_back(b, w);
        g[b].emplace_back(a, w);
    }

    vector<bool> visited(n);
    ll ans = 1LL << 60;

    function<void(int, ll)> dfs = [&](int v, ll current) -> void {
        visited[v] = true;
        if (v == n - 1) {
            ans = min(ans, current);
        }
        for (const auto& [nv, cost] : g[v]) {
            if (visited[nv]) continue;
            dfs(nv, current ^ cost);
        }
        visited[v] = false;
    };
    dfs(0, 0);

    cout << ans << endl;
    return 0;
}