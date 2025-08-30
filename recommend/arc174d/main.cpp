#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


int main() {
    vector<ll> ans0(20);
    ans0[1] = 1;
    for (ll i = 1; 2*i + 1 < 20; ++i) {
        ans0[2*i] = (ll)pow(10, i) + 1;
        ans0[2*i + 1] = ans0[2*i] - 1;
    }
    vector<ll> p10(19);
    for (ll i = 0; i < 19; ++i) {
        p10[i] = pow(10, i);
    }

    auto numDigits = [](ll x) -> ll {
        ll res = 0;
        while (x > 0) {
            x /= 10;
            ++res;
        }
        return res;
    };

    auto solve = [&]() {
        ll n;
        cin >> n;
        ll d = numDigits(n);
        ll ans = 0;
        for (ll i = 1; i < d; ++i) {
            ans += ans0[i];
        }
        if (d%2) {
            // 10^(d-1), ...
            ans += min(ans0[d], n - p10[d-1] + 1);
        } else {
            // 10^(d/2)・(10^(d/2)-2), 10^(d/2)・(10^(d/2)-1), ...
            if (n >= p10[d/2] * (p10[d/2] - 2)) ++ans;
            if (n >= p10[d/2] * (p10[d/2] - 1)) ans += n - p10[d/2] * (p10[d/2] - 1) + 1;
        }
        
        cout << ans << endl;
    };

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}