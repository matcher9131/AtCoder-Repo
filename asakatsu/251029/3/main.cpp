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
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    vector<ll> ans;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        ll x = a[0] ^ b[i];
        for (ll j = 0; j < n; ++j) {
            c[j] = a[j] ^ x;
        }
        sort(c.begin(), c.end());
        if (c == b) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    cout << ans.size() << endl;
    for (const ll ansi : ans) {
        cout << ansi << "\n";
    }

    return 0;
}