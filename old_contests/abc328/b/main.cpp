#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i+1];
    }

    ll ans = 0;
    for (ll i = 1; i <= 9; ++i) {
        if (i <= n) {
            if (a[i] >= i) ++ans;
            if (a[i] >= 11 * i) ++ans;
        }
        if (11* i <= n) {
            if (a[11*i] >= i) ++ans;
            if (a[11*i] >= 11*i) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}