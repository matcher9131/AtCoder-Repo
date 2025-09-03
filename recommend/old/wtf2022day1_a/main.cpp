#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<ll> x(m);
    for (ll i = 0; i < m; ++i) {
        cin >> x[i];
        --x[i];
    }
    
    vector<ll> c(n);
    for (ll i = 0; i < m; ++i) {
        ++c[x[i]];
    }
    sort(c.begin(), c.end());
    
    ll ans = max(0LL, n+b-a);
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        sum += c[i];
        if (sum <= b) ans = max(ans, i+1);
    }

    cout << ans << endl;

    return 0;
}