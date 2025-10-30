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
    ll n, m;
    cin >> n >> m;
    vector<unordered_set<ll>> a(m);
    vector<vector<ll>> revA(n);
    for (ll i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll aij;
            cin >> aij;
            --aij;
            a[i].insert(aij);
            revA[aij].push_back(i);
        }
    }
    vector<ll> b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }

    ll ans = 0;
    for (const ll bi : b) {
        for (const ll ai : revA[bi]) {
            a[ai].erase(bi);
            if (a[ai].empty()) ++ans;
        }
        cout << ans << endl;
    }

    return 0;
}