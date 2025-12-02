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
    ll n, a, b;
    cin >> n >> a >> b;
    ll k;
    cin >> k;
    unordered_set<ll> p;
    p.insert(a);
    p.insert(b);
    for (ll i = 0; i < k; ++i) {
        ll pi;
        cin >> pi;
        p.insert(pi);
    }

    cout << ((ll)p.size() == k+2 ? "YES" : "NO") << endl;

    return 0;
}