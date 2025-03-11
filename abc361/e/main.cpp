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
    vector<vector<pair<int, ll>>> g(n, vector<pair<int, ll>>());
    ll allCosts = 0;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        --a; --b;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
        allCosts += c;
    }

    function<pair<ll, int>(int, int)> dfs = [&](int from, int parent) -> pair<ll, int> {
        pair<ll, int> farthest = { 0LL, from };
        for (const auto& [to, cost] : g[from]) {
            if (to == parent) continue;
            auto farthestChild = dfs(to, from);
            farthestChild.first += cost;
            farthest = max(farthest, farthestChild);
        }
        return farthest;
    };

    auto [dist1, v1] = dfs(0, -1);
    auto [diameter, _] = dfs(v1, -1);

    cout << 2 * allCosts - diameter << endl;

    return 0;
}