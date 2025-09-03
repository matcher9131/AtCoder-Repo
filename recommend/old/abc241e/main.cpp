#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/scc>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    atcoder::scc_graph g(n);
    for (ll i = 0; i < n; ++i) {
        g.add_edge(i, (i + a[i]) % n);
    }
    vector<ll> groupRev(n);
    auto groups = g.scc();
    for (ll i = 0; i < (ll)groups.size(); ++i) {
        for (const ll v : groups[i]) {
            groupRev[v] = i;
        }
    }

    ll ans = 0;
    ll cur = 0;
    while (k > 0) {
        ll gi = groupRev[cur];
        ll groupSize = groups[gi].size();
        if (groupSize > 1) {
            ll q = k / groupSize;
            ll r = k % groupSize;
            ans += q * accumulate(groups[gi].begin(), groups[gi].end(), 0LL, [&](ll acc, ll val) { return acc + a[val]; });
            while (r--) {
                ans += a[cur];
                cur = ans % n;
            }
            break;
        } else if (a[cur] % n == 0) {
            // 自己ループ
            ans += k * a[cur];
            break;
        } else {
            --k;
            ans += a[cur];
            cur = ans % n;
        }
    }

    cout << ans << endl;

    return 0;
}