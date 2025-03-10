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
    vector<vector<pair<int, int>>> g(n, vector<pair<int, int>>());
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x; --y;
        g[x].emplace_back(y, z);
        g[y].emplace_back(x, z);
    }

    vector<int> value(n);
    vector<bool> visited(n);

    function<void(int, vector<int>&)> dfs = [&](int from, vector<int> &components) -> void {
        components.push_back(from);
        visited[from] = true;
        for (const auto& [to, w] : g[from]) {
            if (visited[to]) {
                if (value[to] != (value[from] ^ w)) {
                    cout << -1 << endl;
                    exit(0);
                }
            } else {
                value[to] = value[from] ^ w;
                dfs(to, components);
            }
        }
    };

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        vector<int> components;
        dfs(i, components);
        for (int bit = 0; bit < 30; ++bit) {
            int numOne = 0;
            for (const int v : components) {
                if (value[v] & 1 << bit) ++numOne;
            }
            if (numOne < components.size() - numOne) {
                for (const int v : components) {
                    if (value[v] & 1 << bit) ans[v] |= 1 << bit;
                }
            } else {
                for (const int v : components) {
                    if ((value[v] & 1 << bit) == 0) ans[v] |= 1 << bit;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i == n - 1];
    }
    
    return 0;
}