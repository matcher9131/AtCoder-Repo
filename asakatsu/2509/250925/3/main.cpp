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

    set<pair<ll, ll>> ans;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j) continue;
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            if (dx == 0) ans.emplace(0, dy > 0 ? 1 : -1);
            else if (dy == 0) ans.emplace(dx > 0 ? 1 : -1, 0);
            else {
                ll g = gcd(dx, dy);
                ans.emplace(dx/g, dy/g);
            }
        }
    }

    cout << ans.size() << endl;

    return 0;
}