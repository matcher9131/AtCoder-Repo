#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    ll N = 2e6 + 5;
    vector<mint> fact(N+1);
    fact[0] = 1;
    for (ll i = 1; i <= N; ++i) {
        fact[i] = i * fact[i-1];
    }

    mint ans = 0;
    for (ll j = c1; j <= c2; ++j) {
        ans += fact[j+r2+1] / (fact[j+1] * fact[r2]);
        ans -= fact[j+r1] / (fact[j+1] * fact[r1-1]);
    }
    cout << ans.val() << endl;

    return 0;
}