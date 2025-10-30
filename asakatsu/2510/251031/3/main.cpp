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
    ll x;
    cin >> x;

    unordered_map<ll, mint> memo;
    auto dfs = [&](auto dfs, ll n) -> mint {
        if (memo.contains(n)) return memo[n];
        if (n <= 4) return n;
        return memo[n] = dfs(dfs, n/2) * dfs(dfs, (n+1)/2);
    };
    cout << dfs(dfs, x).val() << endl;

    return 0;
}