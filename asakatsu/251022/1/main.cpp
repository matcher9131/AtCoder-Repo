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
    ll n, d;
    cin >> n >> d;
    string s;
    cin >> s;

    for (ll j = 0; j < d; ++j) {
        for (ll i = n - 1; i >= 0; --i) {
            if (s[i] == '@') {
                s[i] = '.';
                break;
            }
        }
    }
    cout << s << endl;

    return 0;
}