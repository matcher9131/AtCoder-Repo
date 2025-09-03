#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        --a[i];
        --b[i];
    }
    ll m = 4e5;

    atcoder::dsu d(m);
    vector<bool> onCycle(m);
    for (ll i = 0; i < n; ++i) {
        if (d.same(a[i], b[i])) onCycle[a[i]] = true;
        d.merge(a[i], b[i]);
    }

    ll ans = 0;
    for (const auto &v : d.groups()) {
        if (any_of(v.begin(), v.end(), [&](int i) { return onCycle[i]; })) {
            ans += v.size();
        } else {
            ans += (ll)v.size() - 1;
        }
    }

    cout << ans << endl;
    return 0;
}