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
    map<ll, ll> io;
    for (ll i = 0; i < n; ++i) {
        ll ai, bi;
        --ai;
        cin >> ai >> bi;
        ++io[ai];
        --io[ai+bi];
    }

    vector<ll> ans(n+1);
    ll prev = 0;
    ll cur = 0;
    for (const auto &[d, c] : io) {
        ans[cur] += d - prev;
        cur += c;
        prev = d;
    }

    for (ll i = 1; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}