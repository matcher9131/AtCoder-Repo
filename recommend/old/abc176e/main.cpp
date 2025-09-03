#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll h, w, m;
    cin >> h >> w >> m;
    set<pair<ll, ll>> target;
    vector<pair<ll, ll>> cRow(h), cCol(w);
    for (ll i = 0; i < h; ++i) {
        cRow[i].second = i;
    }
    for (ll j = 0; j < w; ++j) {
        cCol[j].second = j;
    }
    for (ll i = 0; i < m; ++i) {
        ll hi, wi;
        cin >> hi >> wi;
        --hi;
        --wi;
        target.emplace(hi, wi);
        ++cRow[hi].first;
        ++cCol[wi].first;
    }
    sort(cRow.begin(), cRow.end(), greater<>());
    sort(cCol.begin(), cCol.end(), greater<>());

    ll ans = 0;
    for (ll ri = 0; ri < h; ++ri) {
        auto [vr, i] = cRow[ri];
        for (ll cj = 0; cj < w; ++cj) {
            auto [vc, j] = cCol[cj];
            if (target.contains({i,j})) {
                ans = max(ans, vr + vc - 1);
            } else {
                if (vr + vc > ans) ans = vr + vc;
                else break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}