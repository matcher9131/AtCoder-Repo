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

const ll B = 27;
const ll MOD1 = 998244353;
const ll MOD2 = 1000000007;

void solve() {
    string a, b;
    cin >> a >> b;
    ll n = a.size();

    ll ha1 = 0, ha2 = 0;
    ll hb1 = 0, hb2 = 0;
    for (ll i = 0; i < n; ++i) {
        ha1 = (ha1 * B + (a[i] - '0')) % MOD1;
        ha2 = (ha2 * B + (a[i] - '0')) % MOD2;
        hb1 = (hb1 * B + (b[i] - '0')) % MOD1;
        hb2 = (hb2 * B + (b[i] - '0')) % MOD2;
    }

    for (ll i = 0; i < n; ++i) {
        if (ha1 == hb1 && ha2 == hb2) {
            cout << i << endl;
            return;
        }
        ha1 -= (a[i] - '0') * atcoder::pow_mod(B, n-1, MOD1);
        if (ha1 < 0) ha1 += MOD1;
        ha1 *= B;
        ha1 += (a[i] - '0');
        ha1 %= MOD1;
        ha2 -= (a[i] - '0') * atcoder::pow_mod(B, n-1, MOD2);
        if (ha2 < 0) ha2 += MOD2;
        ha2 *= B;
        ha2 += (a[i] - '0');
        ha2 %= MOD2;
    }

    cout << -1 << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}