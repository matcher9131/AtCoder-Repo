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
    ll n, nq;
    cin >> n >> nq;
    string s;
    cin >> s;

    vector<ll> c(n+1);
    bool isA = false;
    for (ll i = 0; i < n; ++i) {
        if (isA && s[i] == 'C') {
            c[i+1] = c[i] + 1;
            isA = false;
        } else {
            c[i+1] = c[i];
            isA = s[i] == 'A';
        }
    }

    while (nq--) {
        ll l, r;
        cin >> l >> r;
        --l;
        ll ans = c[r] - c[l] - (s[l] == 'C' && l > 0 && s[l-1] == 'A');
        cout << ans << endl;
    }

    return 0;
}