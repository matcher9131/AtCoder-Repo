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
    vector<string> s(n);
    vector<ll> p(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i] >> p[i];
    }

    vector<ll> num(n);
    for (ll i = 0; i < n; ++i) {
        num[i] = i;
    }
    sort(num.begin(), num.end(), [&](ll i, ll j) {
        return s[i] == s[j] ? p[i] > p[j] : s[i] < s[j];
    });

    for (ll i = 0; i < n; ++i) {
        cout << num[i]+1 << endl;
    }

    return 0;
}