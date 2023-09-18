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
    vector<vector<pair<ll, int>>> g(n, vector<pair<ll, int>>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a;
        --b;
        g[a].emplace_back(w, b);
        g[b].emplace_back(w, a);
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
    }

    function<bool(int, int, vector<int>&, int)> dfs = [&](int x, int from, vector<int> &color, int c) {
        color[from] = c;
        for (const auto &[cost, to] : g[from]) {
            if (cost >= x) break;
            if (color[to] == c) return false;
            if (color[to] != 0) continue;
            if (!dfs(x, to, color, -c)) return false;
        }
        return true;
    };

    auto isOK = [&](int x) {
        vector<int> color(n);
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                if (!dfs(x, i, color, 1)) return false;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (g[i].size() >= 2 && g[i][0].first + g[i][1].first < x) return false;
        }
        return true;
    };
    
    function<int()> binary_search = [&]() {
        int ng = 2e9 + 1;
        int ok = 0;

        while (abs(ok - ng) > 1) {
            int mid = (int)(((ll)ok + ng) / 2);
            if (isOK(mid)) ok = mid;
            else ng = mid;
        }
        
        return ok;
    };

    cout << binary_search() << endl;

    return 0;
}