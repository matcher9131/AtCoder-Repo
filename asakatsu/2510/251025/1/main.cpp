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

    vector<ll> a(n);
    while (nq--) {
        ll k, x;
        cin >> k >> x;
        --x;
        if (k == 1) ++a[x];
        else if (k == 2) a[x] += 2;
        else cout << (a[x] >= 2 ? "Yes" : "No") << endl;
    }

    return 0;
}