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
    int n, m, k;
    cin >> n >> m >> k;
    if (k % 2) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].emplace_back(v, i);
        g[v].emplace_back(u, i);
    }

    vector<bool> visited(n);
    vector<bool> on(n);
    int numOn = 0;
    vector<int> ans;
    function<void(int)> dfs = [&](int from) -> void {
        visited[from] = true;
        for (const auto& [to, ei] : g[from]) {
            if (visited[to]) continue;
            dfs(to);
            if (!on[to] && numOn < k) {
                numOn -= (on[from] ? 1 : 0) + (on[to] ? 1 : 0);
                on[from] = !on[from];
                on[to] = !on[to];
                numOn += (on[from] ? 1 : 0) + (on[to] ? 1 : 0);
                ans.push_back(ei);
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        dfs(i);
    }

    if (numOn == k) {
        cout << "Yes" << endl;
        cout << ans.size() << endl;
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i] + 1 << " \n"[i == (int)ans.size() - 1];
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}