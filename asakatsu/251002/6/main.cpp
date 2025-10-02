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
    vector<ll> a(n), t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> t[i];
    }

    ll lx = -INF, rx = INF, k = 0;
    for (ll i = 0; i < n; ++i) {
        if (t[i] == 1) {
            k += a[i];
        } else if (t[i] == 2) {
            if (a[i] > rx + k) {
                lx = 0;
                rx = 0;
                k = a[i];
            } else if (a[i] > lx + k) {
                lx = a[i] - k;
            }
        } else {
            if (a[i] < lx + k) {
                lx = 0;
                rx = 0;
                k = a[i];
            } else if (a[i] < rx + k) {
                rx = a[i] - k;
            }
        }
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll x;
        cin >> x;
        cout << (x < lx ? lx + k : x > rx ? rx + k : x + k) << endl;
    }

    return 0;
}