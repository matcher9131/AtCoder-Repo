#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using mint = atcoder::modint998244353;
constexpr ll INF = 1e18;
template<typename T> inline void chmin(T &x, T y) { if (y < x) x = y; }
template<typename T> inline void chmax(T &x, T y) { if (x < y) x = y; }

void solve() {
    ll n;
    cin >> n;
    string s;
    cin >> s;

    vector<ll> l0(n), r0(n), l1(n), r1(n);
    l0[0] = s[0] == '1';
    l1[0] = s[0] == '0';
    ll num0 = s[0] == '0', num1 = s[0] == '1';
    for (ll i = 1; i < n; ++i) {
        if (s[i] == '0') {
            l0[i] = l0[i-1];
            l1[i] = i+1 + num1;
            ++num0;
        } else {
            l0[i] = i+1 + num0;
            l1[i] = l1[i-1];
            ++num1;
        }
    }
    if (num0 == n || num1 == n) {
        cout << 0 << endl;
        return;
    }

    r0[n-1] = s[n-1] == '1';
    r1[n-1] = s[n-1] == '0';
    num0 = s[n-1] == '0', num1 = s[n-1] == '1';
    for (ll i = n - 2; i >= 0; --i) {
        if (s[i] == '0') {
            r0[i] = r0[i+1];
            r1[i] = n-i + num1;
            ++num0;
        } else {
            r0[i] = n-i + num0;
            r1[i] = r1[i+1];
            ++num1;
        }
    }

    ll ans = min(s[0] == '0' ? r0[1] : r1[1], s[n-1] == '0' ? l0[n-2] : l1[n-2]);
    for (ll i = 1; i < n-1; ++i) {
        chmin(ans, s[i] == '0' ? l0[i-1] + r0[i+1] : l1[i-1] + r1[i+1]);
    }
    cout << ans << endl;

    // for (ll i = 0; i < (ll)l0.size(); ++i) {
    //     cout << l0[i] << " \n"[i == (ll)l0.size() - 1];
    // }
    // for (ll i = 0; i < (ll)r0.size(); ++i) {
    //     cout << r0[i] << " \n"[i == (ll)r0.size() - 1];
    // }
    // for (ll i = 0; i < (ll)l1.size(); ++i) {
    //     cout << l1[i] << " \n"[i == (ll)l1.size() - 1];
    // }
    // for (ll i = 0; i < (ll)r1.size(); ++i) {
    //     cout << r1[i] << " \n"[i == (ll)r1.size() - 1];
    // }
}

int main() {
    ll t;
    cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}