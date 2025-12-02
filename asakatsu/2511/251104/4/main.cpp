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
    ll k;
    cin >> k;
    ll n = s.size();

    for (ll i = 0; i < n; ++i) {
        if (k == 0) break;
        if (s[i] == 'a') continue;
        ll c = 26 - (s[i] - 'a');
        if (k >= c) {
            s[i] = 'a';
            k -= c;
        }
    }
    s[n-1] = (char)((s[n-1] - 'a' + k) % 26 + 'a');

    cout << s << endl;

    return 0;
}