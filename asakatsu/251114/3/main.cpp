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
    vector<double> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    vector<double> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    auto f = [&](double x) -> double {
        ll i = upper_bound(a.begin(), a.end(), 2*x) - a.begin();
        double res = x * i + s[n] - s[i] - (n-i) * x;
        return res / n;
    };

    double l = 0;
    double r = 1e9;
    for (ll ci = 0; ci < 100; ++ci) {
        double ml = (2*l + r) / 3;
        double mr = (l + 2*r) / 3;
        if (f(mr) > f(ml)) r = mr;
        else l = ml;
    }

    cout << fixed << setprecision(15) << f(l) << endl;

    return 0;
}