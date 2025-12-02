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
    
    string ans;
    for (ll i = 59; i >= 0; --i) {
        ans += 'B';
        if (n & (1LL << i)) ans += "A";
    }

    cout << ans << endl;

    return 0;
}