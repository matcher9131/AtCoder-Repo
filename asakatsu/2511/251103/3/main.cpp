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
    ll n, x0, y0;
    cin >> n >> x0 >> y0;
    string s;
    cin >> s;

    map<pair<ll, ll>, bool> g;
    g[{n, n}] = true;
    ll x = 0, y = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'N') ++x;
        else if (s[i] == 'S') --x;
        else if (s[i] == 'W') ++y;
        else if (s[i] == 'E') --y;
        g[{x+n, y+n}] = true;
        cout << g[{x+x0+n, y+y0+n}];
    }
    cout << endl;

    return 0;
}