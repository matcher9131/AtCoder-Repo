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
    ll n = stoll(s);

    for (ll i = 10; ; ++i) {
        string t = to_string(i);
        ll m = t.size();
        ll fi = 0;
        for (ll j = 0; j < m; ++j) {
            fi *= i;
            fi += t[j] - '0';
        }
        if (fi == n) {
            cout << i << endl;
            return 0;
        } else if (fi > n) {
            break;
        }
    }
    cout << -1 << endl;

    return 0;
}