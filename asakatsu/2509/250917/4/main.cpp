#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());

    ll ans = 0;
    ll i = 0;
    while (i < n) {
        ll j = upper_bound(t.begin(), t.end(), t[i] + k) - t.begin();
        ++ans;
        if (j-i <= c) {
            i = j;
        } else {
            i += c;
        }
    }
    cout << ans << endl;

    return 0;
}