#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n;
    cin >> n;

    mint ans = 0;
    for (ll y = 1; y*y <= n; ++y) {
        ll cz = n/y - y;
        ll cx = y-1;
        ans += 1; // x = y = z
        ans += 3*cz; // x = y < z
        ans += 3*cx; // x < y = z
        ans += cz * cx * 6; // x < y < z
    }
    cout << ans.val() << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}