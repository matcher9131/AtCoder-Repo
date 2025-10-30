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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    ll exceptOne = accumulate(a.begin() + 1, a.end(), 0LL);
    if (a[0] < exceptOne + k) {
        cout << 0 << endl;
        return 0;
    }

    mint ans = 1;
    for (ll i = 1; i < n; ++i) {
        // B(a[i]+k-1, k-1)
        mint numer = 1, denom = 1;
        for (ll j = 1; j < k; ++j) {
            numer *= a[i] + j;
            denom *= j;
        }
        ans *= numer / denom;
    }
    ll rest = a[0] - exceptOne - k;
    // B(rest+k-1, k-1)
    mint numer = 1, denom = 1;
    for (ll j = 1; j < k; ++j) {
        numer *= rest + j;
        denom *= j;
    }
    ans *= numer / denom;
    cout << ans.val() << endl;

    return 0;
}