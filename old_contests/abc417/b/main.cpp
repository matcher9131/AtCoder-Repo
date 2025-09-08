#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    map<ll, ll> a;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        ++a[ai];
    }
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }


    vector<ll> ans;
    for (const ll bi : b) {
        if (a.contains(bi)) {
            --a[bi];
            if (a[bi] == 0) a.erase(bi);
        }
    }

    for (const auto &[val, count] : a) {
        for (ll c = 0; c < count; ++c) {
            ans.push_back(val);
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}