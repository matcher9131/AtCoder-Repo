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
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    vector<unordered_map<int, ll>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        g[a][b] = w;
        g[b][a] = w;
    }

    ll ans = 0;
    queue<int> leaf;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1) {
            leaf.push(i);
        }
    }

    while (!leaf.empty()) {
        int v = leaf.front();
        leaf.pop();
        if (g[v].size() == 0) continue;
        auto [nv, w] = *g[v].begin();
        ans += abs(x[v]) * w;
        x[nv] += x[v];
        g[v].erase(nv);
        g[nv].erase(v);
        if (g[nv].size() == 1) {
            leaf.push(nv);
        }
    }

    cout << ans << endl;
    return 0;
}