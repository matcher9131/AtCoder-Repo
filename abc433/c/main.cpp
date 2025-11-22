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

    vector<pair<ll, ll>> rle;
    ll left = 0;
    for (ll i = 0; i < n; ++i) {
        if (i == n-1 || s[i+1] != s[i]) {
            rle.emplace_back(s[i] - '0', i+1 - left);
            left = i+1;
        }
    }

    ll ans = 0;
    ll m = rle.size();
    for (ll i = 0; i < m-1; ++i) {
        if (rle[i].first + 1 == rle[i+1].first) {
            ans += min(rle[i].second, rle[i+1].second);
        }
    }
    cout << ans << endl;

    return 0;
}