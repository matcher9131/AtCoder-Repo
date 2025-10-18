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
    ll s, a, b, x;
    cin >> s >> a >> b >> x;

    ll ans = 0;
    while (x > 0) {
        ll aa = min(x, a);
        ans += aa * s;
        x -= a+b;
    }
    cout << ans << endl;

    return 0;
}