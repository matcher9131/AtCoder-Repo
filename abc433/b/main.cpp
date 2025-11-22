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

    vector<ll> ans(n, -1);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < i; ++j) {
            if (a[j] > a[i]) ans[i] = j;
        }
    }

    for (ll i = 0; i < n; ++i) {
        cout << (ans[i] == -1 ? -1 : ans[i]+1) << endl;
    }

    return 0;
}