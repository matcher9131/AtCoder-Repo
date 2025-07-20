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
using namespace std;
using ll = long long;

int n;
vector<vector<int>> g;
vector<ll> depth;
vector<ll> sub;
vector<ll> ans;

void dfs(int from, int p, ll d) {
    depth[from] = d;
    for (const int to : g[from]) {
        if (to == p) continue;
        dfs(to, from, d + 1);
        sub[from] += sub[to];
    }
}

void dfsAns(int from, int p) {
    for (const int to : g[from]) {
        if (to == p) continue;
        ans[to] = ans[from] + n - 2 * sub[to];
        dfsAns(to, from);
    }
}

int main() {
    cin >> n;
    g = vector<vector<int>>(n, vector<int>());
    depth = vector<ll>(n);
    sub = vector<ll>(n, 1);
    ans = vector<ll>(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(0, -1, 0);

    ans[0] = accumulate(depth.begin(), depth.end(), 0LL);
    dfsAns(0, -1);

    for (const ll answer : ans) cout << answer << endl;

    return 0;
}