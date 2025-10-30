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
    vector<ll> index(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        index[i] = i;
    }
    sort(index.begin(), index.end(), [&](ll i, ll j) { return a[i] < a[j]; });
    sort(a.begin(), a.end());

    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ll j = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
        ans[index[i]] = s[n] - s[j];
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}