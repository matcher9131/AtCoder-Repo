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

    if (all_of(a.begin(), a.end(), [&](ll val) { return val == a[0]; })) {
        cout << -1 << endl;
        return 0;
    }

    ll r = 1;
    while (a[r] == a[r-1]) ++r;
    vector<ll> seg;
    ll left = r;
    while (left < n+r) {
        ll right = left;
        while (right < n+r && a[right%n] == a[left%n]) ++right;
        seg.push_back(right - left);
        left = right;
    }

    ll ans = 0;
    for (const ll len : seg) {
        chmax(ans, (len+1) / 2);
    }
    cout << ans << endl;

    return 0;
}