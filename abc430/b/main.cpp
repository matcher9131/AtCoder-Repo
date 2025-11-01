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
    ll n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i];
    }

    set<vector<string>> t;
    for (ll i0 = 0; i0 < n-m+1; ++i0) {
        for (ll j0 = 0; j0 < n-m+1; ++j0) {
            vector<string> part;
            for (ll i = 0; i < m; ++i) {
                part.push_back(s[i0+i].substr(j0, m));
            }
            t.insert(part);
        }
    }
    cout << t.size() << endl;

    return 0;
}