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

constexpr ll INF = 1e18 + 1;
constexpr ll MIN = -1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u;
        --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, -w);
    }

    vector<ll> answer(n, INF);
    function<void(int,ll)> setAnswer = [&](int u, ll value) {
        answer[u] = value;
        for (const auto& [v, w] : g[u]) {
            if (answer[v] != INF) continue;
            setAnswer(v, answer[u] + w);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (answer[i] != INF) continue;
        setAnswer(i, 0);
    }

    for (int i = 0; i < n; ++i) {
        cout << answer[i] << " \n"[i == n - 1];
    }

    return 0;
}