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
    string s, t;
    cin >> s >> t;

    vector<ll> d;
    for (ll i = 0; i < n; ++i) {
        if (s[i] != t[i]) d.push_back(i);
    }
    ll m = d.size();

    if (m%2) {
        cout << -1 << endl;
        return 0;
    }

    ll rest = m/2;
    string ans(n, '0');
    for (ll i = 0; i < m; ++i) {
        if (rest == 0) {
            ans[d[i]] = s[d[i]] == '0' ? '1' : '0';
        } else if (m-i == rest) {
            ans[d[i]] = s[d[i]];
            --rest;
        } else {
            if (s[d[i]] == '0') --rest;
        }
    }
    cout << ans << endl;

    return 0;
}