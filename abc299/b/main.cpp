#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
    }
    vector<ll> r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> r[i];
    }

    ll maxValue = 0;
    ll ans = -1;
    ll color = c[0];
    for (ll i = 0; i < n; ++i) {
        if (c[i] == t) {
            if (color != t || r[i] > maxValue) {
                maxValue = r[i];
                ans = i;
                color = t;
            }
        } else if (c[i] == color) {
            if (r[i] > maxValue) {
                maxValue = r[i];
                ans = i;
            }
        }
    }

    cout << ans+1 << endl;
    return 0;
}