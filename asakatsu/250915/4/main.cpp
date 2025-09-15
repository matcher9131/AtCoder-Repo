#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n, d;
    cin >> n >> d;
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        l[i] -= d;
        --r[i];
    }

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> queR;
    for (ll i = 0; i < n; ++i) {
        queR.emplace(r[i], i);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> queL;
    for (ll i = 0; i < n; ++i) {
        queL.emplace(l[i], i);
    }
    vector<bool> destroyed(n);
    ll ans = 0;
    while (!queR.empty()) {
        auto [ri, i] = queR.top();
        queR.pop();
        if (destroyed[i]) continue;
        ++ans;
        while (!queL.empty()) {
            auto [lj, j] = queL.top();
            if (destroyed[j]) {
                queL.pop();
                continue;
            }
            if (lj <= ri) {
                queL.pop();
                destroyed[j] = true;
            } else {
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}