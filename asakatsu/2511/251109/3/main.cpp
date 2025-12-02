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
    ll n, x, y;
    cin >> n >> x >> y;

    vector<ll> red(n);
    red[n-1] = 1;
    vector<ll> blue(n);

    for (ll i = n - 1; i >= 1; --i) {
        red[i-1] += red[i];
        blue[i] += x * red[i];
        red[i] = 0;
        red[i-1] += blue[i];
        blue[i-1] += y * blue[i];
        blue[i] = 0;
    }

    cout << blue[0] << endl;

    return 0;
}