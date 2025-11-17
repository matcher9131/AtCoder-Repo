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
    ll x, y, z;
    cin >> x >> y >> z;
    if (x < y) swap(x, y);

    if (z < x || z > x + 1) {
        cout << 0 << endl;
        return;
    }

    if (x == y) {
        mint l = mint(10).pow(x-1);
        mint r = mint(10).pow(x) - mint(10).pow(y-1);
        mint d = mint(10).pow(y-1);
        mint u = mint(10).pow(x) - mint(10).pow(x-1);
        mint ans = (1 + r-l) * (u-d) / 2;
        cout << (x == z ? ans : 81 * mint(10).pow(x-1) * mint(10).pow(y-1) - ans).val() << endl; 
    } else {
        mint l = mint(10).pow(x-1);
        mint r1 = mint(10).pow(x) - mint(10).pow(y-1);
        mint r2 = mint(10).pow(x) - mint(10).pow(y);
        mint d = mint(10).pow(y-1);
        mint u = mint(10).pow(y);
        mint ans = (r2-l+1 + r1-l) * (u-d) / 2;
        cout << (x == z ? ans : 81 * mint(10).pow(x-1) * mint(10).pow(y-1) - ans).val() << endl; 
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