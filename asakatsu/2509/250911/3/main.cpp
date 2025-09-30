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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll i = 0;
    for (ll j = 0; j < m; ++j) {
        while (i < n && a[i] < b[j]) ++i;
        if (i == n) {
            cout << "NO" << endl;
            return 0;
        }
        ++i;
    }

    cout << "YES" << endl;

    return 0;
}