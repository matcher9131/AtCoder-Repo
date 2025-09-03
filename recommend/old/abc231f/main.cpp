#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;


int main() {
    ll n;
    cin >> n;
    // ai, bi
    vector<pair<ll, ll>> p(n);
    vector<ll> c(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].first;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].second;
        c[i] = p[i].second;
    }
    sort(p.begin(), p.end(), [](pair<ll, ll> &x, pair<ll, ll> &y) {
        // a_i昇順→b_i降順
        return x.first == y.first ? y.second < x.second : x.first < y.first;
    });
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    for (ll i = 0; i < n; ++i) {
        p[i].second = lower_bound(c.begin(), c.end(), p[i].second) - c.begin();
    }
    atcoder::fenwick_tree<ll> fw(n);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += fw.sum(p[i].second, n);
        fw.add(p[i].second, 1);
    }

    ll left = 0;
    while (left < n) {
        ll right = left;
        while (right < n && p[left] == p[right]) ++right;
        ll count = right - left;
        ans += count * (count+1) / 2;
        left = right;
    }
    
    cout << ans << endl;
    return 0;
}