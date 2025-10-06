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
    ll n, m;
    cin >> n >> m;
    if (n >= m) {
        cout << 0 << endl;
        return 0;
    }
    vector<ll> a(m);
    for (ll i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<ll> b(m-1);
    for (ll i = 0; i < m-1; ++i) {
        b[i] = a[i+1] - a[i];
    }
    sort(b.begin(), b.end());

    cout << accumulate(b.begin(), b.begin() + m - n, 0LL) << endl;

    return 0;
}