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
    string s;
    cin >> s;
    s += '_';

    ll ans = 0;
    ll left = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i+1] != s[i]) {
            ll c = i+1 - left;
            ans += c * (c-1) / 2;
            left = i+1;
        }
    }
    cout << ans << endl;

    return 0;
}