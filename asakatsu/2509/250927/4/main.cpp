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
    vector<string> a(n+1);
    cin >> a[0];

    vector<vector<ll>> c(n+1);
    for (ll i = 0; i < (ll)a[0].size(); ++i) {
        c[0].push_back(1);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < (ll)a[i].size() / 3; ++j) {
            ll c0 = (a[i][3*j] == '0') + (a[i][3*j+1] == '0') + (a[i][3*j+2] == '0');
            ll c1 = 3-c0;
            char v = c0 > c1 ? '0' : '1';
            a[i+1] += v;
            vector<ll> t;
            for (ll k = 0; k < 3; ++k) {
                if (a[i][3*j+k] == v) t.push_back(c[i][3*j+k]);
            }
            sort(t.begin(), t.end());
            c[i+1].push_back(abs(c1-c0) == 3 ? t[0] + t[1] : t[0]);
        }
    }

    cout << c[n][0] << endl;

    return 0;
}