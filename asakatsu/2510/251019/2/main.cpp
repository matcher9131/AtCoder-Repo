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
    ll x, k;
    cin >> x >> k;

    for (ll i = 0; i < k; ++i) {
        x = (x + 5 * (ll)pow(10, i)) / (ll)pow(10, i+1) * (ll)pow(10, i+1);
    }
    cout << x << endl;

    return 0;
}