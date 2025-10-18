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
    ll n;
    cin >> n;

    for (ll d = 1; d * d * d <= n; ++d) {
        if (n%d) continue;
        ll z = n/d;
        // 3y^2 + 3yd + d^2 - z = 0
        auto f = [&](ll y) -> ll {
            return 3*y*y + 3*y*d + d*d - z;
        };
        ll left = 1;
        ll right = 1e9;
        while (right - left > 1) {
            ll mid = (left + right) / 2;
            if (f(mid) <= 0) left = mid;
            else right = mid;
        }
        if (f(left) == 0) {
            cout << left+d << " " << left << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}