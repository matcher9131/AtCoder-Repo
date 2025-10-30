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

    string base = "ABXY";
    vector<string> patterns(16);
    for (ll i = 0; i < 4; ++i) {
        for (ll j = 0; j < 4; ++j) {
            patterns[4*i+j] += base[i];
            patterns[4*i+j] += base[j];
        }
    }

    ll ans = INF;
    for (ll i = 0; i < 16; ++i) {
        for (ll j = i+1; j < 16; ++j) {
            string l = patterns[i];
            string r = patterns[j];
            ll count = 0;
            for (ll k = 0; k < n; ++k) {
                if (k < n-1) {
                    if ((s[k] == l[0] && s[k+1] == l[1]) || (s[k] == r[0] && s[k+1] == r[1])) {
                        ++k;
                        ++count;
                        continue;
                    }
                }
                ++count;
            }
            chmin(ans, count);
        }
    }
    cout << ans << endl;

    return 0;
}