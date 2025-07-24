#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(k);
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> memo(n+1, INF);
    function<ll(ll)> dfs = [&](ll rest) -> ll {
        if (memo[rest] != INF) return memo[rest];
        if (rest == 0) return 0;

        ll res = -INF;
        for (const ll ai : a) {
            if (ai > rest) break;
            ll score = -dfs(rest - ai);
            res = max(res, score + ai);
        }
        return memo[rest] = res;
    };

    ll ans = dfs(n);
    cout << (n + ans) / 2 << endl;

    return 0;
}