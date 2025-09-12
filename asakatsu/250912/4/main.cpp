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
    vector<unordered_set<ll>> g(n);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        --a; --b;
        g[a].insert(b);
        g[b].insert(a);
    }

    vector<ll> p;
    for (ll i = 0; i < n; ++i) {
        p.push_back(i);
    }

    ll ans = INF;
    do {
        // サイクル1つ
        {
            ll current = 0;
            for (ll i = 0; i < n; ++i) {
                if (!g[p[i]].contains(p[(i+1) % n])) ++current;
            }
            current += m + current - n;
            ans = min(ans, current);
        }
        // サイクル2つ（3頂点とn-3頂点）
        if (n >= 6) {
            ll current = 0;
            for (ll i = 0; i < 3; ++i) {
                if (!g[p[i]].contains(p[i == 2 ? 0 : i+1])) ++current;
            }
            for (ll i = 3; i < n; ++i) {
                if (!g[p[i]].contains(p[i == n-1 ? 3 : i+1])) ++current;
            }
            current += m + current - n;
            ans = min(ans, current);
        }
        // サイクル2つ（4頂点＋4頂点）
        if (n == 8) {
            ll current = 0;
            for (ll i = 0; i < 4; ++i) {
                if (!g[p[i]].contains(p[i == 3 ? 0 : i+1])) ++current;
            }
            for (ll i = 4; i < n; ++i) {
                if (!g[p[i]].contains(p[i == n-1 ? 4 : i+1])) ++current;
            }
            current += m + current - n;
            ans = min(ans, current);
        }
    } while (next_permutation(p.begin(), p.end()));

    cout << ans << endl;
    return 0;
}