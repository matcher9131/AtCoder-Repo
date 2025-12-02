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
    s = "_" + s + "_";
    ll n = s.size();

    vector<pair<char, ll>> other;
    for (ll i = 0; i < n; ++i) {
        if (s[i] != 'x') other.emplace_back(s[i], i);
    }

    ll m = other.size();
    ll ans = 0;
    for (ll i = 0; i < m/2; ++i) {
        if (other[i].first != other[m-1-i].first) {
            cout << -1 << endl;
            return 0;
        }
        ans += abs((other[i+1].second - other[i].second) - (other[m-1-i].second - other[m-1-i-1].second));
    }
    cout << ans << endl;

    return 0;
}