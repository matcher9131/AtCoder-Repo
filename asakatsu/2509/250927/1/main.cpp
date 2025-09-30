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
    ll x1, y1;
    cin >> x1 >> y1;
    ll x2, y2;
    cin >> x2 >> y2;
    ll x3, y3;
    cin >> x3 >> y3;

    ll x = x1 == x2 ? x3 : x1 == x3 ? x2 : x1;
    ll y = y1 == y2 ? y3 : y1 == y3 ? y2 : y1;

    cout << x << " " << y << endl;

    return 0;
}