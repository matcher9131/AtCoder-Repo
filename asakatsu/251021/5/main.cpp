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
    ll n, d;
    cin >> n >> d;

    mint ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (i < n-d) ans += mint(2).pow(i+d);
        ll l = max(1LL, d + i - n + 1);
        ll r = min(d-1, n-i-1);
        if (l <= r) ans += (r-l+1) * mint(2).pow(i+d-2);
    }
    cout << (ans * 2).val() << endl;

    return 0;
}