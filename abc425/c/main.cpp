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
    ll n, nq;
    cin >> n >> nq;
    vector<ll> a(2*n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i+n] = a[i];
    }

    vector<ll> s(2*n+1);
    for (ll i = 0; i < 2*n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    ll offset = 0;
    while (nq--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll c;
            cin >> c;
            offset = (offset + c) % n;
        } else {
            ll l, r;
            cin >> l >> r;
            --l;
            cout << s[offset+r] - s[offset+l] << endl;
        }
    }

    return 0;
}