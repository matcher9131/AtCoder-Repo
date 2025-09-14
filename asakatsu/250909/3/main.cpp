#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = INF;
    for (ll x = -100; x <= 100; ++x) {
        ll cur = 0;
        for (ll i = 0; i < n; ++i) {
            cur += (a[i] - x) * (a[i] - x);
        }
        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}