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
    ll l, r;
    cin >> l >> r;

    auto isOK = [&](ll x) -> bool {
        return min(10*x, (ll)pow(10, ceil(log10(x+1))) + x) > r;
    };

    ll ok = r;
    ll ng = l-1;
    while (ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << r-ok+1 << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}