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
    ll x1, y1, r;
    cin >> x1 >> y1 >> r;
    ll x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;

    cout << (x2 <= x1-r && x1+r <= x3 && y2 <= y1-r && y1+r <= y3 ? "NO" : "YES") << endl;
    auto withinCircle = [&](ll x, ll y) {
        ll dx = x - x1, dy = y - y1;
        return dx*dx + dy*dy <= r*r;
    };
    cout << (withinCircle(x2, y2) && withinCircle(x2, y3) && withinCircle(x3, y2) && withinCircle(x3, y3) ? "NO" : "YES") << endl;

    return 0;
}