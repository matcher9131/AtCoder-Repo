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
    vector<pair<ll, ll>> a(n-1);
    for (ll i = 0; i < n-1; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    vector<ll> ans(n, INF);
    for (const auto &[v, i] : a) {
        chmin(ans[i], v);
        chmin(ans[i+1], v);
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}