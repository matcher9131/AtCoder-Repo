#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += min(a[i], b[i]);
    }

    while (nq--) {
        char c;
        ll x, v;
        cin >> c >> x >> v;
        --x;

        ll prev = min(a[x], b[x]);
        if (c == 'A') {
            a[x] = v;
        } else {
            b[x] = v;
        }
        ll current = min(a[x], b[x]);
        ans += current - prev;
        cout << ans << endl;
    }

    return 0;
}