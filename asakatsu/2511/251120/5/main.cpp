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
    vector<ll> x(n);
    for (ll i = 0; i < n; ++i) {
        cin >> x[i];
        --x[i];
    }
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> db(60, vector<ll>(n));
    db[0] = x;
    for (ll bi = 1; bi < 60; ++bi) {
        for (ll i = 0; i < n; ++i) {
            db[bi][i] = db[bi-1][db[bi-1][i]];
        }
    }

    vector<ll> ans(n);
    for (ll i = 0; i < n; ++i) {
        ans[i] = i;
    }

    for (ll bi = 0; bi < 60; ++bi) {
        if (k & (1LL << bi)) {
            for (ll i = 0; i < n; ++i) {
                ans[i] = db[bi][ans[i]];
            }
        }
    }

    for (ll i = 0; i < (ll)ans.size(); ++i) {
        cout << a[ans[i]] << " \n"[i == (ll)ans.size() - 1];
    }

    return 0;
}