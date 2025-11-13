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
    vector<vector<pair<ll, ll>>> cities(n);
    vector<ll> p(n), y(n);
    for (ll j = 0; j < m; ++j) {
        ll pj, yj;
        cin >> pj >> yj;
        --pj;
        cities[pj].emplace_back(yj, j);
    }
    for (ll i = 0; i < n; ++i) {
        sort(cities[i].begin(), cities[i].end());
    }

    vector<ll> ans(m);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < (ll)cities[i].size(); ++j) {
            auto [_, ci] = cities[i][j];
            ans[ci] = (i+1) * 1000000 + j+1;
        }
    }

    for (const ll ai : ans) {
        cout << setw(12) << setfill('0') << ai << endl;
    }

    return 0;
}