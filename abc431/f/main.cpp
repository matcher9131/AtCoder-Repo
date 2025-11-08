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
    
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<mint> fact(n+1);
    fact[0] =  1;
    for (ll i = 1; i <= n; ++i) {
        fact[i] = fact[i-1] * i;
    }

    unordered_map<ll, ll> m;
    for (const ll ai : a) {
        ++m[ai];
    }

    mint ans = 1;
    for (ll i = 1; i < n; ++i) {
        ll left = lower_bound(a.begin(), a.end(), a[i] - d) - a.begin();
        ans *= i - left + 1;
    }

    for (const auto &[_, c] : m) {
        ans /= fact[c];
    };

    cout << ans.val() << endl;


    return 0;
}