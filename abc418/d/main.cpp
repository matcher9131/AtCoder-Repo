#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    string t;
    cin >> n >> t;

    vector<ll> dp1(n), dp0(n);
    dp1[0] = t[0] == '1' ? 1 : 0;
    dp0[0] = t[0] == '0' ? 1 : 0;
    for (ll i = 1; i < n; ++i) {
        if (t[i] == '1') {
            dp1[i] += 1 + dp1[i-1];
            dp0[i] = dp0[i-1];
        } else {
            dp1[i] += dp0[i-1];
            dp0[i] += 1 + dp1[i-1];
        }
    }
 
    cout << accumulate(dp1.begin(), dp1.end(), 0LL) << endl;
    
    return 0;
}