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
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    function<void(int, int, vector<bool> &)> dfs = [&](int from, int mask, vector<bool> &visited) {
        visited[from] = true;
        for (const auto &[to, w] : g[from]) {
            if (visited[to]) continue;
            if ((w | mask) == mask) {
                dfs(to, mask, visited);
            }
        }
    };

    int ans = (1 << 30) - 1;
    for (int i = 29; i >= 0; --i) {
        vector<bool> visited(n);
        dfs(0, ans ^ (1 << i), visited);
        if (visited[n-1]) ans ^= 1 << i;
    }

    cout << ans << endl;

    return 0;
}