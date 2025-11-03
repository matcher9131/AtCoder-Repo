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
    ll n, m;
    cin >> n >> m;
    vector<ll> p(m);
    vector<string> s(m);
    for (ll i = 0; i < m; ++i) {
        cin >> p[i] >> s[i];
        --p[i];
    }

    vector<bool> ac(n);
    vector<ll> wa(n);
    for (ll i = 0; i < m; ++i) {
        if (s[i] == "AC") {
            ac[p[i]] = true;
        } else {
            if (!ac[p[i]]) ++wa[p[i]];
        }
    }

    ll cac = 0;
    ll cp = 0;
    for (ll i = 0; i < n; ++i) {
        if (ac[i]) {
            ++cac;
            cp += wa[i];
        }
    }

    cout << cac << " " << cp << endl;

    return 0;
}