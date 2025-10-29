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

    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    string ans = "";
    for (ll i = 0; ; ++i) {
        if (n == 0) break;
        else if (abs(n) & (1LL << i)) {
            n -= (i%2 ? -1 : 1) * (1LL << i);
            ans += '1';
        } else {
            ans += '0';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}