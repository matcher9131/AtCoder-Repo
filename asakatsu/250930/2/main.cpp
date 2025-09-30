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
    ll w, b;
    cin >> w >> b;
    string s = "wbwbwwbwbwbwwbwbwwbwbwbw";
    ll n = s.size();
    ll cw = 7;
    ll cb = 5;
    while (w >= 2*cw && b >= 2*cb) {
        w -= cw;
        b -= cb;
    }

    vector<ll> sw(n + 1), sb(n + 1);
    for (ll i = 0; i < n; ++i) {
        sw[i+1] = sw[i] + (s[i] == 'w');
        sb[i+1] = sb[i] + (s[i] == 'b');
    }

    for (ll i = 0; i <= n; ++i) {
        for (ll j = i+1; j <= n; ++j) {
            if (sw[j] - sw[i] == w && sb[j] - sb[i] == b) {
                cout << "Yes" << endl;
                return 0;
            }
            if (w >= cw && b >= cb && sw[j] - sw[i] == w-cw && sb[j] - sb[i] == b-cb) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}