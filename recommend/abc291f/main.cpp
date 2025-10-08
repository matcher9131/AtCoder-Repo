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
    vector<string> s(n);
    vector<set<ll>> revS(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
        for (ll j = 0; j < m; ++j) {
            if (s[i][j] == '1') revS[i+j+1].insert(i);
        }
    }

    vector<ll> dpl(n, INF), dpr(n, INF);
    dpl[0] = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            if (s[i][j] == '1') chmin(dpl[i+j+1], dpl[i] + 1);
        }
    }
    dpr[n-1] = 0;
    for (ll i = n - 2; i >= 0; --i) {
        for (ll j = 0; j < m; ++j) {
            if (s[i][j] == '1') chmin(dpr[i], dpr[i+j+1] + 1);
        }
    }

    vector<ll> ans(n, INF);
    for (ll k = 1; k < n-1; ++k) {
        for (ll i = max(0LL, k-m+1); i < k; ++i) {
            for (ll j = k+1; j < min(n, i+m+1); ++j) {
                if (s[i][j-i-1] == '1') chmin(ans[k], dpl[i] + dpr[j] + 1);
            }
        }
    }

    for (ll i = 1; i < (ll)n-1; ++i) {
        cout << (ans[i] == INF ? -1 : ans[i]) << " \n"[i == n-1 - 1];
    }

    return 0;
}