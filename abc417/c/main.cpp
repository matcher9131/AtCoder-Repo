#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> b(n);
    map<ll, ll> bc;
    for (ll i = 0; i < n; ++i) {
        b[i] = a[i] + i;
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll k = 2 * i - b[i];
        ans += bc[k];
        ++bc[b[i]];
    }

    cout << ans << endl;

    return 0;
}