#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = INF;
    ll aMax = (ll)sqrt(m) + 1;
    for (ll a = 1; a <= min(n, aMax); ++a) {
        ll b = (m + a - 1) / a;
        if (b > n) continue;
        ans = min(ans, a*b);
    }

    cout << (ans < INF ? ans : -1) << endl;

    return 0;
}