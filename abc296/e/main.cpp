#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    atcoder::scc_graph g(n);
    for (ll i = 0; i < n; ++i) {
        g.add_edge(i, a[i]);
    }

    auto groups = g.scc();
    vector<ll> groupRev(n);
    for (ll i = 0; i < (ll)groups.size(); ++i) {
        for (const int v : groups[i]) {
            groupRev[v] = i;
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll gi = groupRev[i];
        if ((ll)groups[gi].size() >= 2 || a[i] == i) {
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}