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

    ll cf = 0;
    for (ll p = 2; p*p <= n; ++p) {
        ll c = 0;
        while (n%p == 0) {
            ++c;
            n /= p;
        }
        if (c > 0) ++cf;
    }
    if (n > 1) ++cf;

    cout << (cf >= 2 ? "Yes" : "No") << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}