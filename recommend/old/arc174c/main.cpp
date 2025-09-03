#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    if (n == 1) {
        cout << "0 0" << endl;
        return 0;
    }

    map<ll, mint> dp;
    function<mint(ll)> dfs = [&](ll i) -> mint {
        if (i >= n) return 0;
        if (dp.contains(i)) return dp[i];

        mint res = i*(n-i)*(1 + dfs(i+1))/(n*n);
        res += (n-i)*(i+1)*dfs(i+1)/(n*n);
        res += (n-i)*(n-i-1)*dfs(i+2)/(n*n);
        res += (mint)i*i/(n*n);
        res /= 1 - (mint)i*i / (n*n);
        return dp[i] = res;
    };

    cout << dfs(0).val() << " " << dfs(1).val() << endl;

    return 0;
}