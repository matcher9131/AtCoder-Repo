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
    ll k;
    cin >> k;
    vector<ll> a(k);
    for (ll i = 0; i < k; ++i) {
        cin >> a[i];
    }

    if (a[k-1] != 2) {
        cout << -1 << endl;
        return 0;
    }

    ll l = 2;
    ll r = 2;
    for (ll i = k - 1; i >= 0; --i) {
        l = (l + a[i] - 1) / a[i] * a[i];
        r = r / a[i] * a[i] + a[i]-1;
        if (l > r) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << l << " " << r << endl;

    return 0;
}