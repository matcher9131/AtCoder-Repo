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
    string name, kit;
    cin >> name >> kit;

    vector<ll> cn(26), ck(26);
    for (ll i = 0; i < n; ++i) {
        ++cn[name[i] - 'A'];
    }
    for (ll i = 0; i < m; ++i) {
        ++ck[kit[i] - 'A'];
    }

    ll ans = 0;
    for (ll i = 0; i < 26; ++i) {
        if (ck[i] == 0) {
            if (cn[i] > 0) {
                cout << -1 << endl;
                return 0;
            }
        } else {
            chmax(ans, (cn[i] + ck[i] - 1) / ck[i]);
        }
    }
    cout << ans << endl;

    return 0;
}