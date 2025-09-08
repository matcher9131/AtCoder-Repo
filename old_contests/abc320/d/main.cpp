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

constexpr ll INF = 1e16;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<tuple<int, ll, ll>>> g(n, vector<tuple<int, ll, ll>>());
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll x, y;
        cin >> a >> b >> x >> y;
        --a;
        --b;
        g[a].emplace_back(b, x, y);
        g[b].emplace_back(a, -x, -y);
    }

    vector<ll> vx(n, INF), vy(n, INF);
    vx[0] = 0;
    vy[0] = 0;

    function<void(int)> dfs = [&](int from) {
        for (const auto [to, xi, yi] : g[from]) {
            if (vx[to] != INF) continue;
            vx[to] = vx[from] + xi;
            vy[to] = vy[from] + yi;
            dfs(to);
        }
    };

    dfs(0);

    for (int i = 0; i < n; ++i) {
        if (vx[i] == INF) {
            cout << "undecidable" << endl;
        } else {
            cout << vx[i] << " " << vy[i] << endl;
        }
    }
}
