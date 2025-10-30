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
    ll n, p, q;
    cin >> n >> p >> q;
    vector<ll> d(n);
    for (ll i = 0; i < n; ++i) {
        cin >> d[i];
    }

    cout << min(p, q + *min_element(d.begin(), d.end())) << endl;

    return 0;
}