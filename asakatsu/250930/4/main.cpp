#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll r, g, b;
    cin >> r >> g >> b;
    set<ll> rem{ r%3, g%3, b%3 };
    ll m = rem.size();
    if (m == 3) {
        cout << -1 << endl;
    } else if (m == 2) {    
        if (r%3 == b%3) swap(g, b);
        else if (g%3 == b%3) swap(r, b);
        cout << max(r,g) << endl;
    } else {
        vector<ll> v{ r, g, b };
        sort(v.begin(), v.end());
        cout << v[1] << endl;
    }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}