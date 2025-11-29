#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
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
    vector<ll> x(n), r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> r[i];
    }
    vector<ll> target;
    for (ll i = 0; i < n; ++i) {
        target.push_back(x[i] - r[i]);
        target.push_back(x[i] + r[i]);
    }
    sort(target.begin(), target.end());
    target.erase(unique(target.begin(), target.end()), target.end());

    vector<ll> order(target.size());
    atcoder::dsu g(target.size());
    for (ll i = 0; i < n; ++i) {
        ll u = lower_bound(target.begin(), target.end(), x[i] - r[i]) - target.begin();
        ll v = lower_bound(target.begin(), target.end(), x[i] + r[i]) - target.begin();
        g.merge(u, v);
        ++order[u];
        ++order[v];
    }

    auto groups = g.groups();
    ll ans = 0;
    for (const auto &group : groups) {
        if ((ll)group.size() == 1) continue;
        ll numEdges = 0;
        for (const ll v : group) numEdges += order[v];
        numEdges /= 2;
        if (numEdges == (ll)group.size() - 1) {
            ans += (ll)group.size() - 1;
        } else {
            ans += (ll)group.size();
        }
    }
    cout << ans << endl;


    return 0;
}
