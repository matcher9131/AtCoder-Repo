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
    double a, b, x;
    cin >> a >> b >> x;
    x /= a;

    if (x >= a*b/2) {
        double c = 2*x/a - b;
        cout << fixed << setprecision(15) << atan((b-c)/a) * 180.0 / acos(-1) << endl;
    } else {
        double h = 2*x/b;
        cout << fixed << setprecision(15) << atan(b/h) * 180.0 / acos(-1) << endl;
    }

    return 0;
}