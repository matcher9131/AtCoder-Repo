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
    ll x, k, d;
    cin >> x >> k >> d;

    x = abs(x);
    ll q = x/d, r = x%d;
    if (k < q) {
        cout << x - k*d << endl;
    } else if (k%2 == q%2) {
        cout << r << endl;
    } else {
        cout << abs(r-d) << endl;
    }

    return 0;
}