#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> r(n), c(n), x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> r[i] >> c[i] >> x[i];
    }
    vector<ll> rc = r;
    sort(rc.begin(), rc.end());
    rc.erase(unique(rc.begin(), rc.end()), rc.end());
    vector<ll> cc = c;
    sort(cc.begin(), cc.end());
    cc.erase(unique(cc.begin(), cc.end()), cc.end());

    map<pair<ll, ll>, ll> cell;
    vector<ll> rSum(n);
    vector<pair<ll, ll>> cSum(n);
    for (ll i = 0; i < n; ++i) {
        cSum[i].second = i;
    }
    for (ll i = 0; i < n; ++i) {
        r[i] = lower_bound(rc.begin(), rc.end(), r[i]) - rc.begin();
        c[i] = lower_bound(cc.begin(), cc.end(), c[i]) - cc.begin();
        cell[{r[i], c[i]}] = x[i];
        rSum[r[i]] += x[i];
        cSum[c[i]].first += x[i];
    }
    vector<ll> rMin(n);
    if (all_of(r.begin(), r.end(), [&](ll val) { return val == r[0]; })) {
        rMin[r[0]] = *min_element(x.begin(), x.end());
    }
    sort(cSum.begin(), cSum.end(), greater<>());
    
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll _j = 0; _j < n; ++_j) {
            ll j = cSum[_j].second;
            ll val = cell.contains({i, j}) ? cell[{i, j}] : 0;
            ans = max(ans, rSum[i] + cSum[_j].first - val);
            if (val == rMin[i]) break;
        }
    }

    cout << ans << endl;
    return 0;
}