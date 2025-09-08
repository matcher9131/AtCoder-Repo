#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> w(n);
    for (ll i = 0; i < n; ++i) {
        cin >> w[i];
    }
    vector<pair<ll, ll>> edge(m);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        edge[i] = { a, b };
    }

    vector<ll> dp(n, INF), prev(n, INF);
    dp[0] = 0;
    for (ll j = n; j > 0; --j) {
        swap(dp, prev);
        dp[0] = 0;
        for (const auto &[u, v] : edge) {
            dp[u] = min(dp[u], prev[v] + j * w[v]);
            dp[v] = min(dp[v], prev[u] + j * w[u]);
        }
    }
    
    for (ll i = 0; i < n; ++i) {
        cout << dp[i] << endl;
    }

    return 0;
}