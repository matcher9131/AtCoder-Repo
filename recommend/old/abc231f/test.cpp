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
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].first;
    }
    for (ll i = 0; i < n; ++i) {
        cin >> p[i].second;
    }
    sort(p.begin(), p.end(), [](pair<ll, ll> &x, pair<ll, ll> &y) {
        // a_i昇順→b_i降順
        return x.first == y.first ? y.second < x.second : x.first < y.first;
    });

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (p[i].first < p[j].first || p[i].second > p[j].second) continue;
            ++ans[i];
        }
    }
    
    
    cout << accumulate(ans.begin(), ans.end(), 0LL) << endl;
    for (ll i = 0; i < n; ++i) {
        printf("i = %lld, ans = %lld\n", i, ans[i]);
    }
    return 0;
}