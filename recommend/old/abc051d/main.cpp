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
    ll n, m;
    cin >> n >> m;
    vector<tuple<ll, ll, ll>> e(m);
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        ll w;
        cin >> a >> b >> w;
        --a; --b;
        d[a][b] = w;
        d[b][a] = w;
        e[i] = { a, b, w };
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    cout << count_if(e.begin(), e.end(), [&](tuple<ll, ll, ll> edge) {
        auto [u, v, w] = edge;
        return d[u][v] < w;
    }) << endl;

    return 0;
}