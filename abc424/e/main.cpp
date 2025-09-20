#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<double> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    auto isOK = [&](double y) -> bool {
        ll c = 0;
        for (ll i = 0; i < n; ++i) {
            ll ki = a[i] > y ? ceil(log2(a[i] / y)) : 0;
            c += (1LL << ki) - 1;
        }
        return c <= k;
    };

    double ng = 0;
    double ok = 1e9;
    for (int i = 0; i < 100; ++i) {
        double mid = (ok+ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }

    //
    // cout << ok << endl;
    //

    map<double, ll> m;
    for (ll i = 0; i < n; ++i) {
        ll ki = a[i] > ok ? ceil(log2(a[i] / ok)) : 0;
        m[a[i] * pow(0.5, ki)] += 1LL << ki;
        k -= (1LL << ki) - 1;
    }
    while (k > 0) {
        auto [v, c] = *m.rbegin();
        ll cc = min(k, c);
        m[v] -= cc;
        m[v/2] += 2*cc;
        k -= cc;
    }

    //
    // for (auto it = m.rbegin(); it != m.rend(); ++it) {
    //     auto [v, c] = *it;
    //     printf("(%lf,%lld) ", v, c);
    // }
    // cout << endl;
    //

    ll xi = 0;
    for (auto it = m.rbegin(); it != m.rend(); ++it) {
        auto [v, c] = *it;
        xi += c;
        if (xi >= x) {
            cout << fixed << setprecision(15) << v << endl;
            return;
        }
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