#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll a, s;
    cin >> a >> s;

    for (ll i = 0; i < 60; ++i) {
        if (a & (1LL << i)) {
            s -= 2 * (1LL << i);
            if (s < 0) {
                cout << "No" << endl;
                return;
            }
        }
    }

    cout << ((~a & s) == s ? "Yes" : "No") << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}