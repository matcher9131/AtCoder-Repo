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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> ans(n);
    ans[0] = a[0];
    ll lcm = x / gcd(x, y) * y;
    ll cx0 = lcm/x, cy0 = lcm/y;
    ll cd = cx0 - cy0;
    for (ll i = 1; i < n; ++i) {
        if ((a[i]-a[0]) % cd) {
            cout << -1 << endl;
            return 0;
        }
        ll q = (a[i]-a[0]) / cd;
        ll cx = q*cx0;
        ll cy = a[0] - q*cy0;
        if (cx > a[i] || cy < 0) {
            cout << -1 << endl;
            return 0;
        }
        ans[i] = cy;
    }

    cout << accumulate(ans.begin(), ans.end(), 0LL) << endl;

    return 0;
}