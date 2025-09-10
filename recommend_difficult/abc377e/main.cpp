#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/math>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }

    vector<vector<ll>> groups;
    vector<pair<ll, ll>> revGroup(n);
    vector<bool> visited(n);
    for (ll i = 0; i < n; ++i) {
        if (visited[i]) continue;
        vector<ll> group{i};
        visited[i] = true;
        ll current = i;
        while (true) {
            if (a[current] == group[0]) break;
            group.push_back(a[current]);
            visited[a[current]] = true;
            current = a[current];
        }
        for (ll j = 0; j < (ll)group.size(); ++j) {
            revGroup[group[j]] = { (ll)groups.size(), j };
        }
        groups.push_back(group);
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        auto [gi, j] = revGroup[a[i]];
        ll m = groups[gi].size();
        j += atcoder::pow_mod(2, k, m) - 1;
        j = (j+m) % m;
        ans[i] = groups[gi][j];
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}