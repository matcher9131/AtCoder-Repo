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
    ll n = s.size();

    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'A') cout << 'T';
        else if (s[i] == 'T') cout << 'A';
        else if (s[i] == 'C') cout << 'G';
        else if (s[i] == 'G') cout << 'C';
    }
    cout << endl;

    return 0;
}