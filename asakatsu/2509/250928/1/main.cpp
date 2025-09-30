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
    vector<ll> t(n);
    for (ll i = 0; i < n; ++i) {
        cin >> s[i] >> t[i];
    }

    *max_element(t.begin(), t.end()) = 0;
    cout << s[max_element(t.begin(), t.end()) - t.begin()] << endl;

    return 0;
}