#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<bool>> c(n, vector<bool>(m));
    vector<ll> ans;
    while (k--) {
        ll ai, bi;
        cin >> ai >> bi;
        --ai;
        --bi;
        c[ai][bi] = true;
        if (all_of(c[ai].begin(), c[ai].end(), [](bool b) { return b; })) ans.push_back(ai);
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}