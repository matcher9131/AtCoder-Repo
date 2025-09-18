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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    function<ll(ll, vector<ll>&)> dfs = [&](ll bi, vector<ll> &v) -> ll {
        if (bi < 0) return 0;
        vector<vector<ll>> nv(2);
        for (const ll val : v) {
            nv[(val >> bi) & 1LL].push_back(val);
        }

        if (nv[0].empty()) return dfs(bi-1, nv[1]);
        else if (nv[1].empty()) return dfs(bi-1, nv[0]);
        else return min(dfs(bi-1, nv[0]), dfs(bi-1, nv[1])) | (1LL << bi);
    };
    
    cout << dfs(29, a) << endl;
    
    return 0;
}