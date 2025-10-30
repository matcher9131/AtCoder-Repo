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
    ll n, t, a;
    cin >> n >> t >> a;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }

    ll ans = -1;
    double diff = INF;
    for (ll i = 0; i < n; ++i) {
        double ti = t - 0.006 * h[i];
        if (abs(ti - a) < diff) {
            ans = i;
            diff = abs(ti - a);
        }
    }
    cout << ans+1 << endl;

    return 0;
}