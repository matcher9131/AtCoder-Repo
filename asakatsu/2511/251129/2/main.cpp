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
    ll n;
    cin >> n;

    vector<ll> rep(13);
    rep[0] = 1;
    for (ll i = 1; i < 13; ++i) {
        rep[i] = 10 * rep[i-1] + 1;
    }

    set<ll> s;
    for (ll i = 0; i < 13; ++i) {
        for (ll j = 0; j < 13; ++j) {
            for (ll k = 0; k < 13; ++k) {
                s.insert(rep[i] + rep[j] + rep[k]);
            }
        }
    }

    auto it = s.begin();
    while (--n) ++it;
    cout << *it << endl;

    return 0;
}