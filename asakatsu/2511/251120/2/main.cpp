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
    vector<string> s(1000);
    for (ll i = 0; i < 1000; ++i) {
        s[i] = to_string(i+1);
    }
    sort(s.begin(), s.end());
    
    for (ll i = 0; i < 1000; ++i) {
        cout << s[i] << "\n";
    }

    return 0;
}