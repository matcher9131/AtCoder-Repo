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
    unordered_map<string, ll> mp;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ++mp[s];
    }
    ll m;
    cin >> m;
    for (ll j = 0; j < m; ++j) {
        string t;
        cin >> t;
        --mp[t];
    }

    ll ans = 0;
    for (const auto &[_, v] : mp) {
        chmax(ans, v);
    }
    cout << ans << endl;

    return 0;
}