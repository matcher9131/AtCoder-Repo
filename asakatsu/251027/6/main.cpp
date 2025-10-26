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
    ll n, a, b, x, y, z;
    cin >> n >> a >> b >> x >> y >> z;

    y = min(y, a*x);
    z = min(z, b*x);
    if (b*y > a*z) {
        swap(a,b);
        swap(y,z);
    }

    if (n/a < a-1) {
        bool priorOne = b*x <= z;
        ll ans = INF;
        for (ll i = 0; i <= n/a; ++i) {
            ll rest = n - a*i;
            chmin(ans, priorOne ? i*y + rest*x : i*y + (rest/b)*z + (rest%b)*x);
        }
        cout << ans << endl;
    } else {
        bool priorOne = a*x <= y;
        ll ans = INF;
        for (ll i = 0; i <= a-1; ++i) {
            ll rest = n - b*i;
            if (rest < 0) break;
            chmin(ans, priorOne ? i*z + rest*x : i*z + (rest/a)*y + (rest%a)*x);
        }
        cout << ans << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}