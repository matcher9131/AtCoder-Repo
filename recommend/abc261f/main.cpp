#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n;
    cin >> n;
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> c[i];
        --c[i];
    }
    atcoder::fenwick_tree<ll> fw(n);
    ll ans = 0;
    vector<vector<ll>> colorMap(n);
    for (ll i = 0; i < n; ++i) {
        ll xi;
        cin >> xi;
        --xi;
        ans += fw.sum(xi+1, n);
        fw.add(xi, 1);
        colorMap[c[i]].push_back(xi);
    }

    atcoder::fenwick_tree<ll> fwc(n);
    for (ll ci = 0; ci < n; ++ci) {
        for (const ll xi : colorMap[ci]) {
            ans -= fwc.sum(xi+1, n);
            fwc.add(xi, 1);
        }
        for (const ll xi : colorMap[ci]) {
            fwc.add(xi, -1);
        }
    }

    cout << ans << endl;
    return 0;
}