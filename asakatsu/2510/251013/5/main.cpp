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
    string s;
    cin >> s;
    ll n = s.size();

    if (n == 2) {
        if (s[0] == s[1]) cout << "1 2" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }

    for (ll i = 0; i < n-2; ++i) {
        if (s[i] == s[i+1] || s[i] == s[i+2] || s[i+1] == s[i+2]) {
            cout << i+1 << " " << i+3 << endl;
            return 0;
        }
    }
    cout << "-1 -1" << endl;

    return 0;
}