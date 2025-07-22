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
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> deg(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
        ++deg[a];
        ++deg[b];
    }

    // 各頂点の隣接頂点の次数
    vector<vector<ll>> nd(n);
    for (ll i = 0; i < n; ++i) {
        for (const ll to : g[i]) {
            nd[i].push_back(deg[to]);
        }
        sort(nd[i].begin(), nd[i].end(), greater<>());
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < (ll)nd[i].size(); ++j) {
            ans = max(ans, 1 + (j+1) * nd[i][j]);
        }
    }

    cout << n - ans << endl;

    return 0;
}