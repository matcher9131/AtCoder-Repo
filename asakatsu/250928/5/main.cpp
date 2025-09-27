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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<mint> fact(n);
    fact[0] = 1;
    for (ll i = 1; i < n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    mint ans = 0;
    for (ll i = 0; i <= k; ++i) {
        ans += fact[n-1] / (fact[i] * fact[n-1-i]) * m * mint(m-1).pow(n-1-i);
    }
    cout << ans.val() << endl;

    return 0;
}