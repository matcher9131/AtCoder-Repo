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
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<pair<ll, ll>> dec;
    for (ll i = 0; i < n-1; ++i) {
        ll j = i;
        while (j < n-1 && p[j] > p[j+1]) ++j;
        if (i < j) dec.emplace_back(i, j);
        i = j;
    }

    ll ans = 0;
    for (const auto &[l, r] : dec) {
        ll i = l;
        while (i > 0 && p[i-1] < p[i]) --i;
        ll j = r;
        while (j < n-1 && p[j] < p[j+1]) ++j;
        ans += (l-i) * (j-r);
    }
    cout << ans << endl;

    return 0;
}