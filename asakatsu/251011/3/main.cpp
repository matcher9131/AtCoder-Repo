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
    ll k, a, b;
    cin >> k >> a >> b;

    if (a+2 >= b || k < a-1) {
        cout << k+1 << endl;
        return 0;
    }

    k -= a-1;
    ll ans = a + (b-a) * (k/2);
    if (k % 2) ++ans;
    cout << ans << endl;

    return 0;
}