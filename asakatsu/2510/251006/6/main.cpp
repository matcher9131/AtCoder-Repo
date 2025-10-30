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
    ll n, k;
    cin >> n >> k;

    vector<ll> t(k+1);
    for (ll i = 0; i < k+1; ++i) {
        cout << "?";
        for (ll j = 0; j < k+1; ++j) {
            if (j == i) continue;
            cout << " " << j+1;
        }
        cout << endl;
        cin >> t[i];
    }
    ll tSum = accumulate(t.begin(), t.end(), 0LL) % 2;

    vector<ll> ans(n);
    for (ll i = 0; i < k+1; ++i) {
        ans[i] = tSum ^ t[i];
    }

    ll tj = accumulate(ans.begin(), ans.begin() + k-1, 0LL) % 2;
    for (ll i = k+1; i < n; ++i) {
        cout << "?";
        for (ll j = 0; j < k-1; ++j) {
            cout << " " << j+1;
        }
        cout << " " << i+1 << endl;
        ll ti;
        cin >> ti;
        ans[i] = ti ^ tj;
    }

    cout << "!";
    for (ll i = 0; i < n; ++i) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}