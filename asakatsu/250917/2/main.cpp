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
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            ans = max(ans, dx*dx + dy*dy);
        }
    }

    cout << fixed << setprecision(15) << sqrt(ans) << endl;

    return 0;
}