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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<ll> b(m);
    for (ll j = 0; j < m; ++j) {
        cin >> b[j];
    }

    vector<ll> s(n+1);
    for (ll i = 0; i < n; ++i) {
        s[i+1] = s[i] + a[i];
    }

    mint ans = 0;
    for (ll i = 0; i < n; ++i) {
        ans += a[i] * (i+1);
    }

    ans *= accumulate(b.begin(), b.end(), 0LL);

    for (ll j = 0; j < m; ++j) {
        mint t = 0;
        for (ll q = 1; q <= n / (j+1); ++q) {
            t += (s[min((j+1)*(q+1)-1, n)] - s[(j+1)*q-1]) * q;
        }
        ans -= b[j] * (j+1) * t;
    }
    
    cout << ans.val() << endl;

    return 0;
}