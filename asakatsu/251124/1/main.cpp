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
    string s;
    cin >> s;

    for (ll i = 0; i <= n-3; ++i) {
        if (s.substr(i, 3) == "ABC") {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}