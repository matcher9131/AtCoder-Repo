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
    double n, m, d;
    cin >> n >> m >> d;

    cout << fixed << setprecision(15);
    if (d == 0) {
        cout << (m-1) / n << endl;
    } else {
        cout << (m-1) * (2*n - 2*d) / n / n << endl;
    }

    return 0;
}