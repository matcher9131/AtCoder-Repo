#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, d;
    cin >> n >> m >> d;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = -1;
    for (ll i = n - 1; i >= 0; --i) {
        auto it = upper_bound(b.begin(), b.end(), a[i] + d);
        if (it == b.begin()) break;
        --it;
        ll bj = *it;
        if (abs(a[i] - bj) > d) continue;
        if (a[i] + bj > ans) ans = a[i] + bj;
        else break;
    }
    for (ll j = m - 1; j >= 0; --j) {
        auto it = upper_bound(a.begin(), a.end(), b[j] + d);
        if (it == a.begin()) break;
        --it;
        ll ai = *it;
        if (abs(ai - b[j]) > d) continue;
        if (ai + b[j] > ans) ans = ai + b[j];
        else break;
    }

    cout << ans << endl;
    return 0;
}