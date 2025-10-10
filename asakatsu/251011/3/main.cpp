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
    ll n, m;
    cin >> n >> m;

    ll r = 0;
    ll ans = 0;
    ll num = 0;
    for (ll i = 1; i <= n; ++i) {
        r = (10*r + 1) % m;
        for (ll j = 1; j < 10; ++j) {
            if (r * j % m == 0) {
                ans = i;
                num = j;
            }
        }
    }

    cout << (ans == 0 ? "-1" : string(ans, '0' + num)) << endl;

    return 0;
}