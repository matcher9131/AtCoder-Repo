#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    ll c = (max(0LL, n-m) + m-k-1) / (m-k);
    n -= c * (m-k);
    if (n == m) n -= m-k;

    if (n == m-1 && k == m-1) {
        cout << 0 << endl;
    } else {
        cout << atcoder::pow_mod(2, n, 10) << endl;
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