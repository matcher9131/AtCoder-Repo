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
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    {
        auto isOK = [&](double x) -> bool {
            vector<double> dp0(n), dp1(n);
            dp1[0] = a[0] - x;
            for (ll i = 1; i < n; ++i) {
                dp0[i] = dp1[i-1];
                dp1[i] = max(dp0[i-1], dp1[i-1]) + a[i] - x;
            }
            return dp0[n-1] >= 0 || dp1[n-1] >= 0;
        }; 
        double ok = 0;
        double ng = 1e9+1;
        for (ll i = 0; i < 50; ++i) {
            double mid = (ok + ng) / 2;
            if (isOK(mid)) ok = mid;
            else ng = mid;
        }
        cout << fixed << setprecision(15) << ok << endl;
    }

    {
        auto isOK = [&](ll x) -> bool {
            vector<ll> dp0(n), dp1(n);
            dp1[0] = a[0] >= x ? 1 : -1;
            for (ll i = 1; i < n; ++i) {
                dp0[i] = dp1[i-1];
                dp1[i] = max(dp0[i-1], dp1[i-1]) + (a[i] >= x ? 1 : -1);
            }
            return dp0[n-1] > 0 || dp1[n-1] > 0;
        };
        ll ok = 0;
        ll ng = 1e9+1;
        while (ng - ok > 1) {
            ll mid = (ok + ng) / 2;
            if (isOK(mid)) ok = mid;
            else ng = mid;
        }
        cout << defaultfloat << ok << endl;
    }

    return 0;
}