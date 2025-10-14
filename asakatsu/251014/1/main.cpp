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
    unordered_set<char> t;
    for (const char ch : s) t.insert(ch);

    cout << (t.contains('A') && t.contains('B') && t.contains('C') ? "Yes" : "No") << endl;

    return 0;
}