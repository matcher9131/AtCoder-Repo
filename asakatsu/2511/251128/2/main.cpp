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
    --n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    
    string ans;
    while (n > 0) {
        ans += 2 * (n%5) + '0';
        n /= 5;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}