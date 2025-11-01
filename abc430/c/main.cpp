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
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    vector<ll> sa(n+1), sb(n+1);
    for (ll i = 0; i < n; ++i) {
        sa[i+1] = sa[i] + (s[i]  == 'a');
        sb[i+1] = sb[i] + (s[i]  == 'b');
    }

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll r0 = lower_bound(sa.begin(), sa.end(), sa[i] + a) - sa.begin();
        ll r1 = lower_bound(sb.begin(), sb.end(), sb[i] + b) - sb.begin() - 1;
        if (r0 <= r1) ans += r1 - r0 + 1;
    }

    cout << ans << endl;

    return 0;
}