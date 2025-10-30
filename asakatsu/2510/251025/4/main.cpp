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
    ll n, k;
    cin >> n >> k;

    if (n >= (1LL << (k-1))) {
        vector<ll> ans(n, 1);
        for (ll i = 0; i < 1LL << (k-1); ++i) {
            ans[i] = i + (1LL << (k-1));
        }
        for (ll i = 0; i < (ll)ans.size(); ++i) {
            cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
        }
    } else {
        vector<ll> ans(n);
        for (ll i = 0; i < n; ++i) {
            ll x = 0;
            for (ll bi = 0; bi < k-1; ++bi) {
                if (i & (1LL << bi)) x |= 1LL << (k-2-bi);
            }
            ans[i] = (1LL << (k-1)) + x;
        }
        for (ll i = 0; i < (ll)ans.size(); ++i) {
            cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
        }
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}