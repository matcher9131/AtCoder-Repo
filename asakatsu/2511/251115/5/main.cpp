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
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }
    vector<ll> q(n), revQ(n+1);
    for (ll i = 0; i < n; ++i) {
        cin >> q[i];
        revQ[q[i]] = i;
    }

    vector<pair<ll, ll>> edges;
    for (ll i = 0; i < n; ++i) {
        for (ll x = p[i]; x <= n; x += p[i]) {
            edges.emplace_back(i, revQ[x]);
        }
    }
    sort(edges.begin(), edges.end(), [](auto a, auto b) {
        return a.first == b.first ? a.second > b.second : a.first < b.first;
    });

    vector<ll> lis;
    for (const auto& [_, bi] : edges) {
        auto it = lower_bound(lis.begin(), lis.end(), bi);
        if (it == lis.end()) {
            lis.push_back(bi);
        } else {
            *it = bi;
        }
    }
    cout << lis.size() << endl;    

    return 0;
}