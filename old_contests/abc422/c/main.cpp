#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;

    auto isOK = [&](ll x) -> bool {
        if (a < x || c < x) return false;
        return (a-x) + b + (c-x) >= x;
    };

    ll ok = 0;
    ll ng = min(a, c) + 1;

    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}