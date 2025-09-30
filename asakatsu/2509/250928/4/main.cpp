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

    vector<ll> s(n+1);

    while (nq--) {
        ll l, r;
        cin >> l >> r;
        --l;
        ++s[l];
        --s[r];
    }

    for (ll i = 0; i < n; ++i) {
        s[i+1] += s[i];
        cout << s[i] % 2;
    }
    cout << endl;

    return 0;
}