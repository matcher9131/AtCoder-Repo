#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

int main() {
    ll n, a, b;
    cin >> n >> a >> b;

    if (a+b-1 > n || a*b < n) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<ll>> p(a);
    for (ll j = 0; j < b; ++j) {
        p[0].push_back(a * (b-1-j));
    }
    for (ll i = 1; i < a; ++i) {
        p[i].push_back(a*b - a + i);
    }
    ll rest = n - (a+b-1);
    for (ll i = 1; i < a; ++i) {
        if (rest <= 0) break;
        for (ll j = 1; j < min(rest+1, b); ++j) {
            p[i].push_back(p[i][0] - a*j);
        }
        rest -= b-1;
    }

    vector<ll> ans;
    for (ll i = 0; i < a; ++i) {
        for (const ll x : p[i]) ans.push_back(x);
    }
    vector<ll> ans2 = ans;
    sort(ans2.begin(), ans2.end());
    ans2.erase(unique(ans2.begin(), ans2.end()), ans2.end());
    for (ll i = 0; i < n; ++i) {
        ans[i] = lower_bound(ans2.begin(), ans2.end(), ans[i]) - ans2.begin() + 1;
    }
    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << ans[i] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}