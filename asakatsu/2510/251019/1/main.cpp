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

    auto isPalindrome = [&](ll l, ll r) -> bool {
        for (ll i = l, j = r; i < j; ++i, --j) {
            if (s[i] != s[j]) return false;
        }
        return true;
    };

    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = i; j < n; ++j) {
            if (isPalindrome(i, j)) chmax(ans, j-i+1);
        }
    }
    cout << ans << endl;

    return 0;
}