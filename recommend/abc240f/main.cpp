#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

ll sum(ll l, ll r, ll count) {
    return (l + r) * count / 2;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ll ans = x[0];
    ll prevB = 0, prevA = 0;
    for (ll i = 0; i < n; ++i) {
        ll l = prevB + x[i];
        ll r = prevB + y[i] * x[i];
        if (l >= 0 && r <= 0 && x[i] != 0) {
            ll j = prevB / (-x[i]);
            ans = max(ans, prevA + sum(l, prevB + j * x[i], j));
        }
        prevA += sum(l, r, y[i]);
        ans = max(ans, prevA);
        prevB = r;
    }

    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}