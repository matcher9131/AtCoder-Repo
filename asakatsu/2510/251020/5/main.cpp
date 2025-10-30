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
    ll n, k;
    cin >> n >> k;
    vector<double> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](double x) -> bool {
        ll c = 0;
        for (const double ai : a) {
            c += ceil(ai / x) - 1;
        }
        return c <= k;
    };

    double ok = 1e9;
    double ng = 1;
    for (ll i = 0; i < 100; ++i) {
        double mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    cout << (ll)ceil(ok) << endl;

    return 0;
}