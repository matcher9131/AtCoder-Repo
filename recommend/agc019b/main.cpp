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

    vector<ll> count(26);
    for (const char ch : s) {
        ++count[ch - 'a'];
    }
    ll ans = n * (n-1) / 2 + 1;
    for (const ll c : count) {
        ans -= c * (c-1) / 2;
    }
    cout << ans << endl;

    return 0;
}