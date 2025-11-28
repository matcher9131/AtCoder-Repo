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
    ll m = 100*n;
    vector<bool> a(m+1), a2;
    a[0] = true;
    for (ll i = 0; i < n; ++i) {
        a2 = a;
        ll pi;
        cin >> pi;
        for (ll j = 0; j <= m-pi; ++j) {
            a2[j+pi] = a2[j+pi] || a[j];
        }
        swap(a, a2);
    }

    cout << count(a.begin(), a.end(), true) << endl;

    return 0;
}