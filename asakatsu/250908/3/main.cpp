#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint1000000007;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<mint> fib(n+1);
    fib[0] = 1, fib[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    mint ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += a[i] * (fib[i] * fib[n-i] - (i == 0 ? 0 : fib[i-1] * fib[n-1-i]));
    }
    cout << ans.val() << endl;

    return 0;
}