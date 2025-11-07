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
    
    auto isOK = [&](ll x) -> bool {
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            sum += min(a[i], x);
        }
        return sum <= k;
    };

    ll ng = 1e12+1;
    ll ok = 0;
    while (ng - ok > 1) {
        ll mid = (ok+ng)/2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    for (ll i = 0; i < n; ++i) {
        ll dif = min(a[i], ok);
        a[i] -= dif;
        k -= dif;
    }

    for (ll i = 0; i < n; ++i) {
        if (k == 0) break;
        if (a[i] > 0) {
            --a[i];
            --k;
        }
    }

    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] << " \n"[i == (ll)a.size() - 1];
    }

    return 0;
}