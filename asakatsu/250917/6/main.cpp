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
    vector<tuple<ll, ll, ll>> tofu(n);
    vector<ll> a;
    a.reserve(6*n);
    for (ll i = 0; i < n; ++i) {
        ll x, y, z;
        cin >> x >> y >> z;
        ll m;
        cin >> m;
        ll xMin = INF, xMax = -INF;
        ll yMin = INF, yMax = -INF;
        ll zMin = INF, zMax = -INF;
        for (ll j = 0; j < m; ++j) {
            ll xi, yi, zi;
            cin >> xi >> yi >> zi;
            xMin = min(xMin, xi);
            xMax = max(xMax, xi);
            yMin = min(yMin, yi);
            yMax = max(yMax, yi);
            zMin = min(zMin, zi);
            zMax = max(zMax, zi);
        }
        a.push_back(xMin);
        a.push_back(yMin);
        a.push_back(zMin);
        a.push_back(x - xMax - 1);
        a.push_back(y - yMax - 1);
        a.push_back(z - zMax - 1);
    }

    ll sumXor = 0;
    for (const ll ai : a) {
        sumXor ^= ai;
    }

    cout << (sumXor == 0 ? "LOSE" : "WIN") << endl;

    return 0;
}