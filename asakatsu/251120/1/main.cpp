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
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<ll> q = p;
    sort(q.begin(), q.end(), greater<>());
    for (ll i = 0; i < n; ++i) {
        cout << find(q.begin(), q.end(), p[i]) - q.begin() + 1 << endl;
    }

    return 0;
}