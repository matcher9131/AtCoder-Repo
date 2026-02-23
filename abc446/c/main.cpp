#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n, d;
    cin >> n >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll i = 0;
    for (ll j = 0; j < n; ++j) {
        ll sum = 0;
        for (; ; ++i) {
            sum += a[i];
            a[i] = 0;
            if (sum > b[j]) {
                a[i] = sum - b[j];
                break;
            }
        }

        for (; i+d <= j; ++i) {
            a[i] = 0;
        }
    }

    cout << accumulate(a.begin(), a.end(), 0LL) << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}