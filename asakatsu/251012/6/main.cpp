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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    ll left = -(n-1) * d, right = -(n-1) * c;
    for (ll i = 0; i < n; ++i) {
        if (a + left <= b && b <= a + right) {
            cout << "YES" << endl;
            return 0;
        }
        left += c+d;
        right += c+d;
    }

    cout << "NO" << endl;

    return 0;
}