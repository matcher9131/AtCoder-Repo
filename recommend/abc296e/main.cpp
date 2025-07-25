#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    atcoder::scc_graph g(n);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        --ai;
        if (i == ai) ++ans;
        g.add_edge(i, ai);
    }

    for (const auto &c : g.scc()) {
        if ((ll)c.size() >= 2) {
            ans += c.size();
        }
    }
    cout << ans << endl;
    return 0;
}