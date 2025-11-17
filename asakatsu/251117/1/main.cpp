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
    string a, b;
    cin >> a >> b;
    string c = a+b;
    ll x = stoll(c);
    ll y = sqrt(x);
    cout << (y*y == x ? "Yes" : "No") << endl;

    return 0;
}