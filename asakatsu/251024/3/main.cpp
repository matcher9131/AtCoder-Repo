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
    vector<ll> s(m);
    vector<char> c(m);
    for (ll i = 0; i < m; ++i) {
        cin >> s[i] >> c[i];
        --s[i];
    }

    string ans(n, '_');
    for (ll i = 0; i < m; ++i) {
        if (ans[s[i]] == '_') {
            ans[s[i]] = c[i];
        } else if (ans[s[i]] != c[i]) {
            cout << -1 << endl;
            return 0;
        }
    }

    if (n == 1) {
        cout << (ans == "_" ? "0" : ans) << endl;
    } else {
        if (ans[0] == '0') {
            cout << -1 << endl;
        } else {
            if (ans[0] == '_') ans[0] = '1';
            for (ll i = 1; i < n; ++i) {
                if (ans[i] == '_') ans[i] = '0';
            }
            cout << ans << endl;
        }
    }

    return 0;
}