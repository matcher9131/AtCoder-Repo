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
    ll n;
    cin >> n;
    double x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;

    double xc = (x0 + x1) / 2;
    double yc = (y0 + y1) / 2;
    double dx = x0 - xc;
    double dy = y0 - yc;

    double theta = 2 * acos(-1) / n;
    double xa = xc + dx * cos(theta) - dy * sin(theta);
    double ya = yc + dx * sin(theta) + dy * cos(theta);
    cout << fixed << setprecision(15) << xa << " " << ya << endl;

    return 0;
}