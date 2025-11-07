#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < n-1; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<vector<ll>> nextOrder(n);
    for (ll i = 0; i < n; ++i) {
        for (const ll to : g[i]) {
            nextOrder[i].push_back(g[to].size());
        }
        sort(nextOrder[i].begin(), nextOrder[i].end(), greater<>());
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < (ll)nextOrder[i].size(); ++j) {
            chmax(ans, 1 + (j+1) * nextOrder[i][j]);
        }
    }
    cout << n-ans << endl;

    return 0;
}