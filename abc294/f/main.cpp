#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e16;

int main() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        b[i] += a[i];
    }
    vector<int> c(m), d(m);
    for (ll j = 0; j < m; ++j) {
        cin >> c[j] >> d[j];
        d[j] += c[j];
    }

    auto isOK = [&](double x) -> bool {
        vector<double> exj(m);
        for (ll j = 0; j < m; ++j) {
            exj[j] = c[j] - x * d[j];
        }
        sort(exj.begin(), exj.end());

        ll res = 0;
        for (ll i = 0; i < n; ++i) {
            double exi = a[i] - x * b[i];
            res += m - (lower_bound(exj.begin(), exj.end(), -exi) - exj.begin());
        }
        return res >= k;
    };

    double ok = 0;
    double ng = 1;

    for (ll i = 0; i < 100; ++i) {
        double x = (ok + ng) / 2;
        if (isOK(x)) ok = x;
        else ng = x;
    }

    cout << setprecision(15) << 100.0 * ok << endl;
    return 0;
}