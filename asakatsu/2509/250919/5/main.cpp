#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll m = n/2;

    vector<ll> former;
    for (ll bit = 0; bit < 1LL<<m; ++bit) {
        ll sum = 0;
        for (ll i = 0; i < m; ++i) {
            if (bit & (1LL << i)) sum += a[i];
        }
        if (sum <= t) former.push_back(sum);
    }
    sort(former.begin(), former.end());

    vector<ll> latter;
    for (ll bit = 0; bit < 1LL<<(n-m); ++bit) {
        ll sum = 0;
        for (ll i = 0; i < n-m; ++i) {
            if (bit & (1LL << i)) sum += a[m+i];
        }
        if (sum <= t) latter.push_back(sum);
    }
    sort(latter.begin(), latter.end());

    ll ans = 0;
    for (const ll tf : former) {
        ll tl = *(upper_bound(latter.begin(), latter.end(), t-tf) - 1);
        ans = max(ans, tf + tl);
    }
    cout << ans << endl;

    return 0;
}