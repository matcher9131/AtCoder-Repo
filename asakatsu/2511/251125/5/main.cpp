#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    auto moveBefore = [&](ll sx, ll sy, ll gx, ll gy) {
        if (sx != gx && sy != gy) return abs(gx-sx) + abs(gy-sy);
        if (sx == gx) return abs(gy-sy) + (xb == sx && min(sy, gy) < yb && yb < max(sy, gy) ? 2 : 0);
        else return abs(gx-sx) + (yb == sy && min(sx, gx) < xb && xb < max(sx, gx) ? 2 : 0);
    };

    if (xb == xc) {
        ll tx = xb;
        ll ty = yb < yc ? yb-1 : yb+1;
        cout << moveBefore(xa, ya, tx, ty) + abs(yc-yb) << endl;
    } else if (yb == yc) {
        ll tx = xb < xc ? xb-1 : xb+1;
        ll ty = yb;
        cout << moveBefore(xa, ya, tx, ty) + abs(xc-xb) << endl;
    } else {
        ll tx = xb < xc ? xb-1 : xb+1;
        ll ty = yb < yc ? yb-1 : yb+1;
        cout << min(moveBefore(xa, ya, tx, yb), moveBefore(xa, ya, xb, ty)) + abs(xc-xb) + abs(yc-yb) + 2 << endl;
    }

    return 0;
}