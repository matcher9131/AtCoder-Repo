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

    vector<ll> a{ 1, 2, 3, 4, 5, 6 };
    n %= 30;
    for (ll i = 0; i < n; ++i) {
        swap(a[i%5], a[i%5+1]);
    }

    for (ll i = 0; i < 6; ++i) {
        cout << a[i];
    }
    cout << endl;

    return 0;
}