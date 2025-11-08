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

    string t;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'A') t += "BB";
        else t += s[i];
    }

    ll m = t.size();
    ll left = 0;
    char prev = t[0];
    vector<pair<char, ll>> rle;
    for (ll i = 1; i < m; ++i) {
        if (t[i] != prev) {
            rle.emplace_back(prev, i - left);
            left = i;
            prev = t[i];
        }
    }
    rle.emplace_back(prev, m - left);

    for (const auto &[c, l] : rle) {
        if (c == 'B') {
            cout << string(l/2, 'A');
            if (l%2) cout << "B";
        } else {
            cout << string(l, c);
        }
    }
    cout << endl;

    return 0;
}