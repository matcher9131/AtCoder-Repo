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
    string s;
    cin >> s;
    ll n = s.size();

    ll ans = 0;
    for (ull bit = 0; bit < (1ULL << (n-1)); ++bit) {
        ll cur = 0;
        ll x = s[0] - '0';
        for (ll i = 0; i < n-1; ++i) {
            if (bit & (1ULL<<i)) {
                cur += x;
                x = 0;
            } else {
                x *= 10;
            }
            x += s[i+1] - '0';
        }
        cur += x;
        ans += cur;
    }

    cout << ans << endl;

    return 0;
}