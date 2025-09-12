#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

void solve() {
    ll a, b;
    cin >> a >> b;

    if (a >= b) {
        cout << a-b << endl;
        return;
    }

    ll ans = INF;
    ll x = 0;
    while (true) {
        if (x > ans) break;
        ll q = b / (a+x);
        ll r = b % (a+x);
        ll y = r == 0 ? 0 : a+x-r;
        ans = min(ans, x+y);
        if (r < q) ++x;
        else x += r/q;
    }

    cout << ans << endl;
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}