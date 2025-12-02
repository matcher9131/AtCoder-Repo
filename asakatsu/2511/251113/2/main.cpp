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
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    ll m = t.size();

    ll ans = INF;
    for (ll i = 0; i <= n-m; ++i) {
        ll count = 0;
        for (ll j = 0; j < m; ++j) {
            if (s[i+j] != t[j]) ++count;
        }
        chmin(ans, count);
    }
    cout << ans << endl;

    return 0;
}