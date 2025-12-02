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

    for (ll i = 0; i <= n; ++i) {
        for (ll j = 0; j <= n-i; ++j) {
            for (ll k = 0; k <= n-i-j; ++k) {
                cout << i << " " << j << " " << k << "\n"; 
            }
        }
    }

    return 0;
}