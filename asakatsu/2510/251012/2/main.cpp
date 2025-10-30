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

    vector<bool> used(26);
    for (const char ch : s) {
        used[ch - 'a'] = true;
    }

    for (ll i = 0; i < 26; ++i) {
        if (!used[i]) {
            cout << (char)('a' + i) << endl;
            return 0;
        }
    }

    cout << "None" << endl;

    return 0;
}