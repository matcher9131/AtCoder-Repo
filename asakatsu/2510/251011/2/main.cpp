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

    vector<ll> a(n+1);
    a[0] = 2;
    a[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        a[i] = a[i-1] + a[i-2];
    }
    cout << a[n] << endl;

    return 0;
}