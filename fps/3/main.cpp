#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/convolution>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll s;
    cin >> s;

    // f = x^3 + x^4 + ... = x^3 / (1-x)
    // Q = ∑f = 1 / (1-f) = (1-x) / (1 - x - x^3)  (∵ f has no constant term)
    // (1 - x - x^3)Q = 1-x
    // a[n] - a[n-1] - a[n-3] = 1 if n==0 else -1 if n==1 else 0

    vector<mint> ans(s+1);
    ans[0] = 1;
    for (ll i = 3; i <= s; ++i) {
        ans[i] = ans[i-1] + ans[i-3];
    }
    cout << ans[s].val() << endl;

    return 0;
}