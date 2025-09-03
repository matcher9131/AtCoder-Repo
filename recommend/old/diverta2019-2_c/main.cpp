#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    // [0, nr)を符号反転して使う
    int nr = lower_bound(a.begin(), a.end(), 0) - a.begin();
    if (nr == 0) nr = 1;
    else if (nr == n) nr = n-1;

    vector<pair<ll, ll>> ans;
    ll cur = a[0];
    for (ll i = nr; i < n-1; ++i) {
        ans.emplace_back(cur, a[i]);
        cur -= a[i];
    }
    ans.emplace_back(a[n-1], cur);
    cur = a[n-1] - cur;
    for (ll i = 1; i < nr; ++i) {
        ans.emplace_back(cur, a[i]);
        cur -= a[i];
    }

    cout << cur << endl;
    for (const auto &[x, y] : ans) {
        cout << x << " " << y << endl;
    }

    return 0;
}