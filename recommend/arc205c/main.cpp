#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/fenwicktree>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n;
    cin >> n;
    // [t, s, i]
    vector<tuple<ll, ll, ll>> a(n);
    for (ll i = 0; i < n; ++i) {
        ll si, ti;
        cin >> si >> ti;
        --si;
        --ti;
        a[i] = { ti, si, i };
    }
    sort(a.begin(), a.end());

    ll sMax = -INF;
    priority_queue<pair<ll, ll>> right;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> left;
    for (const auto &[ti, si, i] : a) {
        if (si < sMax) {
            cout << "No" << endl;
            return 0;
        }
        sMax = si;
        if (si < ti) right.emplace(ti, i);
        else left.emplace(ti, i);
    }

    vector<ll> ans;
    while (!right.empty()) {
        auto [_, i] = right.top();
        right.pop();
        ans.push_back(i);
    }
    while (!left.empty()) {
        auto [_, i] = left.top();
        left.pop();
        ans.push_back(i);
    }

    cout << "Yes" << endl;
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i]+1 << " \n"[i == (ll)ans.size() - 1];
    }


    return 0;
}