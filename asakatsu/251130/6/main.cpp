#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    

    unordered_map<ll, ll> memo;
    memo[0] = 0;

    auto update = [&](ll key, ll value) -> void {
        if (memo.contains(key)) {
            chmin(memo[key], value);
        } else {
            memo[key] = value;
        }
    };

    auto dfs = [&](auto dfs, ll x) -> ll {
        if (memo.contains(x)) return memo[x];

        {
            ll l = x/2;
            update(x, dfs(dfs, l) + a + (x - 2*l) * d);
            ll r = (x+1)/2;
            if (r != l) update(x, dfs(dfs, r) + a + (2*r - x) * d);
        }
        {
            ll l = x/3;
            update(x, dfs(dfs, l) + b + (x - 3*l) * d);
            ll r = (x+2)/3;
            if (r != l) update(x, dfs(dfs, r) + b + (3*r - x) * d);
        }
        {
            ll l = x/5;
            update(x, dfs(dfs, l) + c + (x - 5*l) * d);
            ll r = (x+4)/5;
            if (r != l) update(x, dfs(dfs, r) + c + (5*r - x) * d);
        }
        if (x <= INT64_MAX / d) update(x, x*d);
        assert(memo[x] >= 0);
        return memo[x];
    };

    cout << dfs(dfs, n) << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}