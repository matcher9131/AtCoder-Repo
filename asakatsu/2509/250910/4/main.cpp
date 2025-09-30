#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

int main() {
    ll n;
    cin >> n;

    auto isOK = [&](ll a, ll b) -> bool {
        return a*a*a + a*a*b + a*b*b + b*b*b >= n;
    };

    ll ans = INF + 1;
    for (ll i = 0; i * i * i <= n; ++i) {
        ll ok = pow(n, 1.0/3.0) + 1;
        ll ng = -1;
        while (ok - ng > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(i, mid)) ok = mid;
            else ng = mid;
        }
        ans = min(ans, i*i*i + i*i*ok + i*ok*ok + ok*ok*ok);
    }

    cout << ans << endl;
    return 0;
}