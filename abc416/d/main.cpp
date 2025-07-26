#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

void solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] %= m;
    }
    sort(a.begin(), a.end(), greater<>());
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        b[i] %= m;
    }
    sort(b.begin(), b.end());

    ll count = 0;
    int i = 0, j = 0;
    while (i < n && j < n) {
        while (j < n && a[i] + b[j] < m) ++j;
        if (j >= n) break;
        count += (a[i] + b[j]) / m;
        ++i;
        ++j;
    }

    ll ans = accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL) - count * m;
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