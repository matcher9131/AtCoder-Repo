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
    vector<ll> a(m+2);
    a[0] = 0;
    for (ll i = 1; i <= m; ++i) {
        cin >> a[i];
    }
    a[m+1] = n+1;
    sort(a.begin(), a.end());

    vector<ll> gap;
    for (ll i = 0; i < m+1; ++i) {
        if (a[i+1] - a[i] == 1) continue;
        gap.push_back(a[i+1] - a[i] - 1);
    }

    ll k = *min_element(gap.begin(), gap.end());
    ll ans = 0;
    for (const ll d : gap) {
        ans += (d + k-1) / k;
    }
    cout << ans << endl;

    return 0;
}