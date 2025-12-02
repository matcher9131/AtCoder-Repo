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
    ll M, D;
    cin >> M >> D;
    ll y, m, d;
    cin >> y >> m >> d;

    ++d;
    if (d > D) {
        ++m;
        d = 1;
    }
    if (m > M) {
        ++y;
        m = 1;
    }
    cout << y << " " << m << " " << d << endl;

    return 0;
}