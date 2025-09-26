#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll h;
    cin >> h;

    unordered_map<ll, ll> memo;
    memo[1] = 1;
    function<ll(ll)> dfs = [&](ll x) -> ll {
        if (memo.contains(x)) return memo[x];
        return 1 + 2 * dfs(x>>1);
    };

    cout << dfs(h) << endl;

    return 0;
}