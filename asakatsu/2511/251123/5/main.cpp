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
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;

    ll la = t1*a1 + t2*a2;
    ll lb = t1*b1 + t2*b2;

    if (la == lb) {
        cout << "infinity" << endl;
        return 0;
    }

    if (la < lb) {
        swap(la, lb);
        swap(a1, b1);
        swap(a2, b2);
    }

    if (a1 > b1) {
        cout << 0 << endl;
    } else {
        ll df = t1*(b1-a1);
        ll da = la-lb;
        cout << 2 * (df/da) + (df%da > 0) << endl;
    }

    return 0;
}