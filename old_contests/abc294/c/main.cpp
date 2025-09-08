#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> c;
    c.reserve(n+m);
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        c.push_back(a[i]);
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
        c.push_back(b[j]);
    }
    sort(c.begin(), c.end());

    for (ll i = 0; i < n; ++i) {
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
    }
    for (ll j = 0; j < m; ++j) {
        b[j] = lower_bound(c.begin(), c.end(), b[j]) - c.begin();
    }

    for (ll i = 0; i < (ll)a.size(); ++i) {
        cout << a[i] + 1 << " \n"[i == (ll)a.size() - 1];
    }
    for (ll j = 0; j < (ll)b.size(); ++j) {
        cout << b[j] + 1 << " \n"[j == (ll)b.size() - 1];
    }

    return 0;
}