#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    ll start = a[0];
    ll goal = a[n-1];
    sort(a.begin(), a.end());

    ll ans = 1;
    auto it = lower_bound(a.begin(), a.end(), start);
    while (true) {
        if (goal <= *it * 2) {
            cout << ans+1 << endl;
            return;
        }
        auto nextIt = upper_bound(a.begin(), a.end(), *it * 2) - 1;
        if (nextIt == it) {
            cout << -1 << endl;
            return;
        }
        ++ans;
        it = nextIt;
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}