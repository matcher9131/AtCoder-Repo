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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        while ((a[i] & 1LL) == 0) {
            a[i] >>= 1;
            ++c[i];
        }
    }
    cout << *min_element(c.begin(), c.end()) << endl;

    return 0;
}