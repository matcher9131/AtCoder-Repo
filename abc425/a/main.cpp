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

    ll ans = 0;
    for (ll i = 1; i <= n; ++i) {
        ans += (i%2 ? -1 : 1) * i * i * i;
    }
    cout << ans << endl;

    return 0;
}