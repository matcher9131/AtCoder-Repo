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
    vector<double> p(n);
    for (ll i = 0; i < n; ++i) {
        double a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        p[i] = a+b+c+d + e*110/900;
    }

    cout << fixed << setprecision(15) << *max_element(p.begin(), p.end()) << endl;

    return 0;
}