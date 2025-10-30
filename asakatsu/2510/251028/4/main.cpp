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
    ll k;
    cin >> k;
    --k;
    
    vector<ll> ans;
    auto dfs = [&](auto dfs, ll n) -> void {
        if (n > 1e10) return;
        ans.push_back(n);
        ll i = n%10;
        if (i > 0) dfs(dfs, 10*n + i-1);
        dfs(dfs, 10*n + i);
        if (i < 9) dfs(dfs, 10*n + i+1);
    };
    for (ll i = 1; i <= 9; ++i) {
        dfs(dfs, i);
    }
    sort(ans.begin(), ans.end());
    cout << ans[k] << endl;

    return 0;
}