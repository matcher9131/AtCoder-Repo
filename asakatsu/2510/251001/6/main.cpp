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
    string s, x;
    cin >> s >> x;
    x += 'T';

    vector<vector<ll>> dp(n+1, vector<ll>(7));
    auto dfs = [&](auto f, ll i, ll j) -> ll {
        if (dp[i][j] != 0) return dp[i][j];
        if (i == n) return j == 0 ? 1 : -1;

        ll sign = x[i] == x[i+1] ? 1 : -1;
        ll res = max(sign * f(f, i+1, 10*j % 7), sign * f(f, i+1, (10*j + (s[i] - '0')) % 7));

        return dp[i][j] = res;
    };

    cout << (((dfs(dfs, 0, 0) > 0) ^ (x[0] == 'A')) ? "Takahashi" : "Aoki") << endl;

    return 0;
}