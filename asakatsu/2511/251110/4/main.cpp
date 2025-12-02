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
    list<ll> a;
    map<ll, list<ll>::iterator> revA;
    for (ll i = 0; i < n; ++i) {
        ll ai;
        cin >> ai;
        a.push_back(ai);
    }
    for (auto it = a.begin(); it != a.end(); ++it) {
        revA[*it] = it;
    }

    ll nq;
    cin >> nq;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x, y;
            cin >> x >> y;
            auto it = revA[x];
            ++it;
            revA[y] = a.insert(it, y);
        } else {
            ll x;
            cin >> x;
            a.erase(revA[x]);
            revA.erase(x);
        }
    }

    for (auto it = a.begin(); it != a.end(); ++it) {
        cout << (it != a.begin() ? " " : "") << *it;
    }
    cout << endl;

    return 0;
}