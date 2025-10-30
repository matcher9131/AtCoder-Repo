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
    ll n, k;
    cin >> n >> k;

    ll q = n/k, r = n%k;

    if (k%2) {
        cout << q*q*q << endl;
    } else {
        ll ans = 0;
        // i = 0;
        ans += q*q*q;
        // i = k/2
        if (r >= k/2) ++q;
        ans += q*q*q;
        cout << ans << endl;
    }

    return 0;
}