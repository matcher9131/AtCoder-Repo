#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> dish(n);
    for (ll i = 0; i < n; ++i) {
        cin >> dish[i].first >> dish[i].second;
    }

    sort(dish.begin(), dish.end(), [](pair<ll, ll> &x, pair<ll, ll> &y) {
        return x.first + x.second < y.first + y.second;
    });
    reverse(dish.begin(), dish.end());

    vector<ll> ans(2);
    for (ll i = 0; i < n; ++i) {
        ans[i%2] += i%2 == 0 ? dish[i].first : dish[i].second;
    }

    cout << ans[0] - ans[1] << endl;

    return 0;
}