#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    map<pair<ll, ll>, map<ll, ll>> vec;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i+1; j < n; ++j) {
            ll dx = x[j] - x[i], dy = y[j] - y[i];
            if (dx == 0) {
                ++vec[{0, 1}][abs(dy)];
            } else if (dy == 0) {
                ++vec[{1, 0}][abs(dx)];
            } else {
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                }
                ll g = gcd(dx, dy);
                dx /= g;
                dy /= g;
                ++vec[{dx, dy}][g];
            }
        }
    }

    ll ans = 0;
    ll numParallelo = 0;
    for (const auto &[v, inner] : vec) {
        // printf("(%lld, %lld)\n", v.first, v.second);
        ll sumCount = 0;
        for (const auto &[g, count] : inner) {
            // printf("g = %lld, count = %lld\n", g, count);
            sumCount += count;
            numParallelo += count * (count - 1) / 2;
        }
        ans += sumCount * (sumCount - 1) / 2;
    }
    ans -= numParallelo / 2;

    cout << ans << endl;
    return 0;
}