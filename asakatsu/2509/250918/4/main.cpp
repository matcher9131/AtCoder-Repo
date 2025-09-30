#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for (ll i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    vector<ll> w(m);
    for (ll j = 0; j < m; ++j) {
        cin >> w[j];
    }
    sort(w.begin(), w.end());

    vector<ll> sl(n/2 + 1), sr(n/2 + 1);
    for (ll i = 0; i < n/2; ++i) {
        sl[i+1] = sl[i] + h[2*i+1] - h[2*i];
        sr[i+1] = sr[i] + h[n-2*i-1] - h[n-2*i-2];
    }

    ll ans = INF;
    for (ll j = 0; j < m; ++j) {
        ll i = upper_bound(h.begin(), h.end(), w[j]) - h.begin();
        ll sum = sl[i/2] + sr[n/2 - i/2] + abs((i%2 ? h[i-1] : h[i]) - w[j]);
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;
}