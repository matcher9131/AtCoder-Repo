#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll ans = n;
    ll l = 0;
    while (l < n-1) {
        ll d = a[l+1] - a[l];
        ll r = l+1;
        while (r < n && a[r] == a[l] + (r-l) * d) ++r;
        ans += (r-l) * (r-l-1) / 2;
        l = r-1; 
    }
    cout << ans << endl;

    return 0;
}