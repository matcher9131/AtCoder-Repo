#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;

    map<ll, ll> memo;
    memo[1] = 0;
    auto dfs = [&](auto f, ll x) -> ll {
        if (memo.contains(x)) return memo[x];
        return memo[x] = x + f(f, x/2) + f(f, (x+1)/2);
    };

    cout << dfs(dfs, n) << endl;

    return 0;
}