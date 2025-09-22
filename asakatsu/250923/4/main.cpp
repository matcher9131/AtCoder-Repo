#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<vector<ll>> g(n);
    vector<ll> c(n, -1);
    for (ll i = 1; i < n; ++i) {
        ll bi;
        cin >> bi;
        --bi;
        g[bi].push_back(i);
    }

    vector<ll> ans(n, -1);
    vector<bool> visited(n);
    function<ll(ll)> dfs = [&](ll from) -> ll {
        ll minFee = INF, maxFee = 0;
        for (const ll to : g[from]) {
            ll feeChild = dfs(to);
            maxFee = max(maxFee, feeChild);
            minFee = min(minFee, feeChild);
        }
        ans[from] = maxFee == 0 ? 1 : minFee + maxFee + 1;
        return ans[from];
    };
    dfs(0);

    cout << ans[0] << endl;

    return 0;
}