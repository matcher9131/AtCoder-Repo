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
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using dsu = atcoder::dsu;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>());
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> depth(n);
    // depth, index
    priority_queue<pair<int, int>> que;
    function<void(int, int, int)> dfs = [&](int from, int parent, int d) -> void {
        depth[from] = d;
        que.emplace(d, from);
        for (const int to : g[from]) {
            if (to == parent) continue;
            dfs(to, from, d + 1);
        }
    };
    dfs(0, -1, 0);

    vector<int> dp(n);
    while (!que.empty()) {
        auto [_, v] = que.top();
        que.pop();
        if (g[v].size() < 4) {
            dp[v] = 1;
        } else {
            vector<int> dpc;
            for (const int child : g[v]) {
                if (depth[v] < depth[child]) {
                    dpc.push_back(dp[child]);
                }
            }
            sort(dpc.begin(), dpc.end());
            dp[v] = dpc[0] + dpc[1] + dpc[2] + 1;
        }
    }
    if (g[0].size() < 4) {
        dp[0] = dp[g[0][0]];
    } else {
        vector<int> dpc;
        for (const int child : g[0]) {
            dpc.push_back(dp[child]);
        }
        sort(dpc.begin(), dpc.end());
        dp[0] = dpc[0] + dpc[1] + dpc[2] + dpc[3];
    }

    int ans = *max_element(dp.begin(), dp.end()) + 1;
    cout << (ans < 5 ? -1 : ans) << endl;


    return 0;
}