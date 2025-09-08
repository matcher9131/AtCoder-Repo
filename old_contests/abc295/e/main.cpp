#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n), c(m+1);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        ++c[a[i]];
    }

    vector<mint> fact(2001);
    fact[0] = 1;
    for (ll i = 1; i <= 2000; ++i) {
        fact[i] = fact[i-1] * i;
    }

    vector<mint> p(m+1);
    for (ll x = 1; x <= m; ++x) {
        ll sumMin = accumulate(c.begin() + 1, c.begin() + x + 1, 0LL);
        if (sumMin + c[0] < k) continue;
        if (sumMin >= k) p[x] = 1;
        else {
            for (ll j = k - sumMin; j <= c[0]; ++j) {
                mint pp = (mint)x / m;
                p[x] += fact[c[0]] / (fact[j] * fact[c[0] - j]) * pp.pow(j) * (1 - pp).pow(c[0] - j);
            }
        }
    }

    mint ans = 0;
    for (ll x = 1; x <= m; ++x) {
        ans += x * (p[x] - p[x-1]);
    }

    cout << ans.val() << endl;
    return 0;
}