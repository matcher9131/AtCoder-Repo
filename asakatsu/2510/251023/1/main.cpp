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

    cout << (n%2 && s[n/2] == '/' && all_of(s.begin(), s.begin() + n/2, [](char ch) { return ch == '1'; }) && all_of(s.rbegin(), s.rbegin() + n/2, [](char ch) { return ch == '2'; }) ? "Yes" : "No") << endl;

    return 0;
}