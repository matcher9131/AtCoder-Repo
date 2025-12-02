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
    ll t = 0;
    for (ll i = 0; i < (ll)s.size(); ++i) {
        t += s[i] - '0';
    }
    cout << (n%t == 0 ? "Yes" : "No") << endl;

    return 0;
}