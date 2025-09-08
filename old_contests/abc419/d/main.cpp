#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    // [l, r)
    vector<ll> l(m), r(m);
    for (ll i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
    }

    vector<ll> inv(n+1);
    for (ll i = 0; i < m; ++i) {
        ++inv[l[i]];
        --inv[r[i]];
    }
    for (ll i = 1; i <= n; ++i) {
        inv[i] += inv[i-1];
    }

    string ans = s;
    for (ll i = 0; i < n; ++i) {
        if (inv[i] % 2) ans[i] = t[i];
    }
    cout << ans << endl;

    return 0;
}