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
    ll x, y, z;
    cin >> x >> y >> z;

    if (x < y*z) {
        cout << "No" << endl;
    } else {
        cout << ((x - y*z) % (z-1) == 0 ? "Yes" : "No") << endl;
    }

    return 0;
}