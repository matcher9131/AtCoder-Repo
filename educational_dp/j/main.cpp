#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll x = 0, y = 0, z = 0;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        if (ai == 3) ++x;
        else if (ai == 2) ++y;
        else if (ai == 1) ++z;
    }

    vector<vector<vector<double>>> dp(n+1, vector<vector<double>>(n+1, vector<double>(n+1, -1.0)));
    dp[0][0][0] = 0;
    function<double(ll,ll,ll)> dfs = [&](ll x, ll y, ll z) -> double {
        if (dp[x][y][z] != -1.0) return dp[x][y][z];
        double res = 1.0;
        if (x > 0) res += dfs(x-1, y+1, z) * x / n;
        if (y > 0) res += dfs(x, y-1, z+1) * y / n;
        if (z > 0) res += dfs(x, y, z-1) * z / n;
        res /= (x + y + z) / (double)n;
        
        return dp[x][y][z] = res;
    };

    cout << setprecision(15) << dfs(x, y, z) << endl;

    return 0;
}