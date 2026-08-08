#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/dsu>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vector<ll> x(n), y(n);
    map<pair<ll, ll>, ll> rev;
    for (ll i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        rev[{x[i], y[i]}] = i;
    }

    // Nが左下壁、N+1が右上壁
    atcoder::dsu d(n+2);
    for (ll i = 0; i < n; ++i) {
        if (x[i] == h-1 || y[i] == 0) d.merge(i, n);
        if (x[i] == 0 || y[i] == w-1) d.merge(i, n+1);
        for (ll dx = -1; dx <= 1; ++dx) {
            for (ll dy = -1; dy <= 1; ++dy) {
                if (dx == 0 && dy == 0) continue;
                ll nx = x[i] + dx, ny = y[i] + dy;
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (rev.contains({nx, ny})) {
                    ll j = rev[{nx, ny}];
                    d.merge(i, j);
                }
            }
        }
    }

    cout << (d.same(n, n+1) ? "No" : "Yes") << endl;

    return 0;
}
