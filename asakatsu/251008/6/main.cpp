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
    string s, t;
    cin >> s >> t;

    vector<vector<ll>> m(26);
    for (ll i = 0; i < (ll)s.size(); ++i) {
        m[s[i] - 'a'].push_back(i);
    }

    auto isOK = [&](ll k) -> bool {
        for (ll ti = 0; ti < (ll)t.size(); ++ti) {
            if ()
        }
    };

    return 0;
}