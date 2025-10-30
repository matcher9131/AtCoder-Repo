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
    string s;
    cin >> s;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    s = s.insert(d, 1, '"');
    s = s.insert(c, 1, '"');
    s = s.insert(b, 1, '"');
    s = s.insert(a, 1, '"');
    cout << s << endl;

    return 0;
}