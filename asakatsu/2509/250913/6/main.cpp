#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    auto f = [&](ll x) -> ll {
        ll res = 0;
        while (x > 0) {
            res += x%10;
            x /= 10;
        }
        return res;
    };

    
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += f(a[i]);
    }
    ans *= 2 * n;

    vector<vector<ll>> b(16, vector<ll>(n));
    for (ll d = 0; d < 16; ++d) {
        ll m = pow(10, d+1);
        for (ll i = 0; i < n; ++i) {
            b[d][i] = a[i] % m;
        }
        sort(b[d].begin(), b[d].end());
    }

    for (ll d = 0; d < 16; ++d) {
        ll m = pow(10, d+1);
        for (ll i = 0; i < n; ++i) {
            ll c = b[d].end() - lower_bound(b[d].begin(), b[d].end(), m-b[d][i]);
            ans -= 9*c;
        }
    }

    cout << ans << endl;

    return 0;
}