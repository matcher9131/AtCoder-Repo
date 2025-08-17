#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
    }

    vector<double> dp(1 << 16, -1);
    function<double(ll)> dfs = [&](ll bit) -> double {
        if (dp[bit] != -1) return dp[bit];
        if (bit == 0) return 0;
        double res = INF;
        for (ll i = 1; i < 15; ++i) {
            double ex = 1.0;
            ll blank = 0;
            if (bit & (1 << (i-1))) ex += dfs(bit ^ (1 << (i-1))) / 3.0;
            else ++blank;
            if (bit & (1 << i)) ex += dfs(bit ^ (1 << i)) / 3.0;
            else ++blank;
            if (bit & (1 << (i+1))) ex += dfs(bit ^ (1 << (i+1))) / 3.0;
            else ++blank;
            if (blank == 3) continue;
            ex *= 3.0 / (3-blank);
            res = min(res, ex);
        }
        return dp[bit] = res;
    };

    ll bit = 0;
    for (ll i = 0; i < n; ++i) {
        bit |= 1 << x[i];
    }
    cout << setprecision(15) << dfs(bit) << endl;

    return 0;
}