#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll nq;
    cin >> nq;
    while (nq--) {
        ll x, k;
        cin >> x >> k;
        --x;
        vector<set<ll>> s(k+1);
        s[0].insert(x);
        for (ll i = 0; i < k; ++i) {
            for (const ll from : s[i]) {
                for (const ll to : g[from]) {
                    if (any_of(s.begin(), s.end(), [&](set<ll> x) { return x.contains(to); })) continue;
                    s[i+1].insert(to);
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i <= k; ++i) {
            for (const ll v : s[i]) {
                ans += v+1;
            }
        }
        cout << ans << endl;
    }

    return 0;
}