#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> dp(k+1);
    for (ll i = 0; i <= k; ++i) {
        if (i < a[0]) dp[i] = -1;
        else {
            ll res = -INF;
            for (auto it = a.begin(); it != upper_bound(a.begin(), a.end(), i); ++it) {
                res = max(res, -dp[i - *it]);
            }
            dp[i] = res;
        }
    }

    cout << (dp[k] == 1 ? "First" : "Second") << endl;

    return 0;
}