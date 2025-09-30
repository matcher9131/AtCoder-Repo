#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, c;
    cin >> n >> c;
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }

    ll prev = -INF;
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (t[i] - prev >= c) {
            ++ans;
            prev = t[i];
        }
    }

    cout << ans << endl;
    return 0;
}