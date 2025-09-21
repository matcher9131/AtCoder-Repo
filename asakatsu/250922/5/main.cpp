#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    vector<ll> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    atcoder::fenwick_tree<ll> sum(n);
    atcoder::fenwick_tree<ll> count(n);

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ll j = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        ans += count.sum(0, j) * a[i] - sum.sum(0, j);
        sum.add(j, a[i]);
        count.add(j, 1);
    }

    cout << ans << endl;
    return 0;
}