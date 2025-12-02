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
    string t;
    cin >> t;

    auto isOK = [](string &s, string s0) -> bool {
        ll m = s.size();
        for (ll i = 0; i < m; ++i) {
            if (s[i] != s0[i%3]) return false;
        }
        return true;
    };

    if (n == 1) {
        cout << (t == "1" ? (ll)2e10 : (ll)1e10) << endl;
    } else if (n == 2) {
        if (t == "00") cout << 0 << endl;
        else if (t == "01") cout << (ll)1e10 - 1 << endl;
        else cout << (ll)1e10 << endl;
    } else {
        if (isOK(t, "110")) {
            ll c = (n+2) / 3;
            cout << (ll)1e10 - c + 1 << endl;
        } else if (isOK(t, "101")) {
            ll c = (n+3) / 3;
            cout << (ll)1e10 - c + 1 << endl;
        } else if (isOK(t, "011")) {
            ll c = (n+4) / 3;
            cout << (ll)1e10 - c + 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}